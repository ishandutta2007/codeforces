#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
typedef long long ll;
ll read();
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=5e5+5;
int t,n,m,bel[N],idc,nxt[N];
ll c[N],sum[N];
int tmp[N],tot;
vector<int> G[N];
signed main() {
	t=read();
	while(t--) {
		n=read(),m=read();
		fr(i,1,n) c[i]=read(),G[i].clear();
		for(int i=1,u,v;i<=m;++i) {
			u=read(),v=read();
			G[u].push_back(v);
		}
		idc=1; fr(i,1,n) bel[i]=1;
		fr(i,1,n) {
			tot=0;
			for(auto v:G[i]) tmp[++tot]=bel[v];
			sort(tmp+1,tmp+tot+1);
			tot=unique(tmp+1,tmp+tot+1)-tmp-1;
			fr(i,1,tot) nxt[tmp[i]]=++idc;
			for(auto v:G[i]) bel[v]=nxt[bel[v]];
		}
		ll ans=0;
		fr(i,1,idc) sum[i]=0;
		fr(i,1,n) sum[bel[i]]+=c[i];
		fr(i,2,idc) ans=__gcd(ans,sum[i]);
		printf("%lld\n",ans);
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
inline ll read() {
	static ll x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}