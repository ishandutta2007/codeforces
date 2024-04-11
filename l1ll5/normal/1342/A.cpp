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
int t;
int x,y;
int a,b;
main()
{
    t=read();
    while(t--)
    {
        x=read(),y=read();
        a=read(),b=read();

        int ans=0;

        if(2*a<=b) // all a
        {
            ans=(x+y)*a;
        }
        else
        {
            int mn=min(x,y);
            ans=mn*b;
            x-=mn,y-=mn;
            ans+=(x+y)*a;
        }
        printf("%lld\n",ans);
    }
}