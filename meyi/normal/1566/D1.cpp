#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
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
		T ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<ll>t;
int a[maxn],b[maxn],bl,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%*d%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
		sort(b+1,b+n+1);
		bl=unique(b+1,b+n+1)-b-1;
		t.mx_idx=bl;
		t.clear();
		ll ans=0;
		for(ri i=1;i<=n;++i){
			a[i]=lower_bound(b+1,b+bl+1,a[i])-b;
			ans+=t.query(a[i]-1);
			t.add(a[i],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}