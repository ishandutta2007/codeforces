#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=4e5+10;
int a[maxn],b[maxn],bl,m,n,t_case,x[maxn];
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		ri ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>c;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	bl=0;
	for(ri i=1;i<=n;++i){
		scanf("%d",x+i);
		b[++bl]=a[i]-x[i];
		b[++bl]=x[i]-a[i];
	}
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	c.mx_idx=bl;
	c.clear();
	ll ans=0;
	for(ri i=1;i<=n;++i){
		ans+=c.query(bl)-c.query(lower_bound(b+1,b+bl+1,x[i]-a[i])-b);
		c.add(lower_bound(b+1,b+bl+1,a[i]-x[i])-b,1);
	}
	printf("%lld\n",ans);
	return 0;
}