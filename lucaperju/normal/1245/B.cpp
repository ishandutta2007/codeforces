#include <bits/stdc++.h>

using namespace std;
char v[105];
char rz[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int ca=a,cb=b,cc=c;
        int s=0;
        for(int i=1; i<=n; ++i)
        {
            char ch;
            cin>>ch;
            v[i]=ch;
            if(ch=='R')
            {
                if(b)
                    --b,++s;
            }
            else if (ch=='P')
            {
                if(c)
                    --c,++s;
            }
            else if(a)
                --a,++s;
        }
        if(s>=(n+1)/2)
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
            continue;
        }
        a=ca;
        b=cb;
        c=cc;
        for(int i=1; i<=n; ++i)
        {
            int ch=v[i];
            rz[i]=0;
            if(ch=='R')
            {
                if(b)
                {
                    --b;
                    rz[i]='P';
                }
                /*    else
                    if(a)
                    {
                        --a;
                        cout<<'R';
                    }
                    else
                    if(c)
                    {
                        --c;
                        cout<<'S';
                    }*/
            }
            else if (ch=='P')
            {
                if(c)
                {
                    --c;
                    rz[i]='S';
                }
                /*       else
                       if(a)
                       {
                           --a;
                           cout<<'R';
                       }
                       else
                       if(b)
                       {
                           --b;
                           cout<<'P';
                       }*/
            }
            else
            {
                if(a)
                {
                    --a;
                    rz[i]='R';
                }
                /*       else
                       if(c)
                       {
                           --c;
                           cout<<'S';
                       }
                       else
                       if(b)
                       {
                           --b;
                           cout<<'P';
                       }*/
            }
        }
        for(int i=1; i<=n; ++i)
            {
                if(rz[i]==0)
                {
                    if(a)
                    {
                        --a;
                        rz[i]='R';
                    }
                    else if(c)
                    {
                        --c;
                        rz[i]='S';
                    }
                    else if(b)
                    {
                        --b;
                        rz[i]='P';
                    }
                }
                cout<<rz[i];
            }
        cout<<'\n';
    }
    return 0;
}