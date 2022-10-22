#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e3+10,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
		}
	}
}d;
int cnt,m,n,k;
inline ll qpow(ll x,ll y){
	ll ret=1;
	for(;y;x=x*x%mod,y>>=1)if(y&1)ret=ret*x%mod;
	return ret;
}
signed main(){
	scanf("%d%d%d",&n,&m,&k);
	d.init(n);
	for(ri i=1;i+k-1<=n;++i){
		ri j=i+k-1;
		for(ri l=i;l<j;++l,--j)d.merge(l,j);
	}
	for(ri i=1;i<=n;++i)
		if(d.find(i)==i)
			++cnt;
	printf("%lld",qpow(m,cnt));
	return 0;
}