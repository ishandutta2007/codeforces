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
const int N=1005;
const ll inf=1000000000000000000ll;
int n;ll a[N],b[N];ll ans,s[N];
int main()
{
    n=rd();ans=0;
    rep(i,1,n)a[i]=rd(),b[i]=a[i];
    rep(i,1,n)if(~i&1)b[i]=-b[i];
    rep(i,1,n)s[i]=s[i-1]+b[i];
    for(int l=1;l<=n;l+=2)
    {
        ll tl=1;
        for(int r=l+1;r<=n;r+=2)
        {
            ll t=s[r-1]-s[l];
            ll lb=max(tl+t,1ll);
            ll rb=min(a[l]+t,a[r]);
            if(lb<=rb)ans+=rb-lb+1;
//            cout<<l<<" "<<r<<" "<<ans<<endl;
            tl=max(tl,-(s[r]-s[l]));
        }
    }
    printf("%lld\n",ans);
    return 0;
}