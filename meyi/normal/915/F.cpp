#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int fr,to,v;
	inline bool operator<(const edge &k)const{
		return v<k.v;
	}
}e[maxn];
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){fa[x]=y,siz[y]+=siz[x];}
}d;
int a[maxn],n;
ll ans;
inline void calc(){
	d.init(n);
	sort(e+1,e+n);
	for(ri i=1;i<n;++i){
		ri x=d.find(e[i].fr),y=d.find(e[i].to);
		ans+=1ll*d.siz[x]*d.siz[y]*e[i].v;
		d.merge(x,y);
	}
}
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<n;++i)scanf("%d%d",&e[i].fr,&e[i].to),e[i].v=max(a[e[i].fr],a[e[i].to]);
	calc();
	for(ri i=1;i<n;++i)e[i].v=-min(a[e[i].fr],a[e[i].to]);
	calc();
	printf("%lld",ans);
	return 0;
}