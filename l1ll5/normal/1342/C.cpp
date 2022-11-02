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
int a,b,q;
int l,r;

int mx,mn,lcm;
int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}

int cal(int x) // 1 - x 
{
    if(x==0) return 0;
    int ret=0;
    int ta=x/lcm; //talcm
    ret+=ta*mx;

    int len=x-ta*lcm; //

    ret+=min(len,mx-1);
    return ret;
}


main()
{
//    freopen("G.in","r",stdin);
//    freopen("data.out","w",stdout);
    t=read();
    while(t--)
    {
        a=read(),b=read(),q=read();

        lcm=a*b/gcd(a,b);
        mx=max(a,b),mn=min(a,b);

        for(int i=1;i<=q;i++)
        {
            l=read(),r=read();
            int ans1=cal(r)-cal(l-1);
            int ans2=(r-l+1)-ans1;
            if(i!=q)
            printf("%lld ",ans2);
            else printf("%lld\n",ans2);
        }
    }
}