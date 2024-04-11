#include<bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;

main()
{
    T=read();
    while(T--)
    {
        string s,t;
        cin>>s;

        int n=s.length();

        int all0=1,all1=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='0') all0=0;
            if(s[i]!='1') all1=0;
        }

        if(all0 || all1)
        {
            cout<<s<<endl;
            continue ;
        }

        int cur=s[0]-'0';


        t.clear();
        t.push_back(cur+'0');

        for(int i=1;i<n;i++)
        {
            if((s[i]-'0')!=cur^1)
            {
                cur^=1;
                t.push_back(cur+'0');
                t.push_back(s[i]);
                cur^=1;
            }
            else
            {
                t.push_back(s[i]);
                cur^=1;
            }
        }
        cout<<t<<endl;
    }
}