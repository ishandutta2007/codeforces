#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],ans,f[maxn],n,pos[maxn],t_case;
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,-0x3f,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		k=n-k+1;
		for(;k<=mx_idx;k+=lowbit(k))ckmax(c[k],v);
	}
	inline T query(int k){
		k=n-k;
		T ret=INT_MIN;
		for(;k;k^=lowbit(k))ckmax(ret,c[k]);
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>t;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),pos[a[i]]=i;
	t.mx_idx=n;
	t.clear();
	for(ri i=1,r=0;i<=n;++i){
		ckmax(ans,f[i]);
		ri nxt=pos[a[i]];
		if(nxt<r)continue;
		r=nxt;
		ckmax(f[r],max(ans+r-i-1,t.query(i)+r-1));
		t.add(r,f[r]-r);
	}
	printf("%d",ans);
	return 0;
}