//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
#define mk make_pair
using namespace std; const int N=500010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,K,a[N],d[N],qz[N],f[N]={(int)(1e18)},g[2][N],res;
inline void Doit()
{
	for(ri int i=2;i<n;i++) res=max(res,max(0ll,a[i]-d[i])+max(g[0][i-1]-a[i],g[1][i+1]));
	for(ri int i=2;i<=n;i++) res=max(res,g[1][i]+max(0ll,qz[i-1]-f[i-1]));
}
signed main()
{
    n=read(), K=read();
	for(ri int i=1;i<=n;i++) a[i]=read();
	for(ri int i=1;i<=n;i++) d[i]=read();
	for(ri int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	for(ri int i=1;i<=n;i++) f[i]=min(f[i-1],d[i]);
	for(ri int i=1;i<=n;i++) g[0][i]=max(g[0][i-1],-d[i]+qz[n]-qz[i-1]);
	for(ri int i=n;i;i--) g[1][i]=max(g[1][i+1],-d[i]+qz[n]-qz[i-1]);
	if(!K) { printf("%lld\n",max(0ll,g[1][1])); return 0; }

	if(K>=2) res=max(res,qz[n]-f[n-1]);
	if(K>=1) Doit();

	printf("%lld\n",res);
    return 0;
}