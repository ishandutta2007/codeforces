#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=100005;
const ll inf=1000000000000000000ll;
int n,n0,n1,a[N],p[N];
int main()
{
    int T=rd();
    while(T--)
    {
        n=rd();
        rep(i,1,n)a[i]=rd()&1;
        n0=0;n1=0;
        rep(i,1,n)n0+=(a[i]==0);
        rep(i,1,n)if(a[i]==1)p[++n1]=i;
        ll ans=inf;
        if(n0==n1||n0==n1+1)
        {
            ll s=0;
            for(int i=2;i<=n;i+=2)s+=abs(p[i/2]-i);
            ans=min(ans,s);
        }
        if(n1==n0||n1==n0+1)
        {
            ll s=0;
            for(int i=1;i<=n;i+=2)s+=abs(p[(i+1)/2]-i);
            ans=min(ans,s);
        }
        if(ans==inf)ans=-1;
        printf("%lld\n",ans);
    }
    return 0;
}