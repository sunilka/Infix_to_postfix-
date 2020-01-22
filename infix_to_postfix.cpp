#include<bits/stdc++.h>
using namespace std;

char stacks[100];
int top = -1;

int getpriority(char ele)
{
    if(ele == '+' || ele =='-')
        return 1;
    else if(ele == '*')
        return 2;
    else if(ele == '^')
        return 3;
}

int main()
{
    string ans;
    string s;
    cout<<"Please enter the infix expression :";
    cin>>s;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i] <='Z')
        {
            ans+=s[i];
        }

        else
        {
            if(top==-1)
            {
                stacks[++top] = s[i];
            }

            else if(s[i] == '(')
            {
                stacks[++top] = s[i];
            }
            else if(s[i] == ')')
            {
                while(stacks[top]!='(')
                {
                    ans+=stacks[top--];
                }
                top--;
            }

            else
            {
                if(stacks[top] == '(' )
                {
                    stacks[++top] = s[i];
                }
                else{
                int elepriority = getpriority(s[i]);
                int toppriority = getpriority(stacks[top]);

                if( elepriority > toppriority)
                {
                    stacks[++top] = s[i];
                }
                else
                {
                    while(toppriority < elepriority || stacks[top]!='(')
                    {
                        ans+=stacks[top--];
                        toppriority = stacks[top];
                    }
                    stacks[++top] = s[i];
                }
            }
            }
        }
        cout<<stacks[top]<<"   s[i] = "<<s[i]<<" ans "<<ans<<endl;
    }

    if(top!=-1)
    {
        while(top!=-1)
        {
            ans+=stacks[top--];
        }
    }
    cout<<"Postfix expression is : "<<endl;
    cout<<ans;
}
