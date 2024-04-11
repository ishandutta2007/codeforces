#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(++k;k<=mx_idx;k+=lowbit(k))ckmax(c[k],v);
	}
	inline T query(int k){
		T ret=0;
		for(++k;k;k^=lowbit(k))ckmax(ret,c[k]);
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>t;
int a[maxn],ans,f[maxn],n;
vector<int>p;
signed main(){
	scanf("%d",&n);
	t.mx_idx=n+1;
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]<=i)p.push_back(i);
	}
	sort(p.begin(),p.end(),[&](const int &x,const int &y){return a[x]!=a[y]?a[x]<a[y]:x>y;});
	for(auto i:p){
		f[i]=t.query(i-a[i])+1;
		ckmax(ans,f[i]);
		t.add(i-a[i],f[i]);
	}
	printf("%d",ans);
	return 0;
}