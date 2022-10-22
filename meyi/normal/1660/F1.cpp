#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn<<1];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k;k^=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		T ret=0;
		for(;k<=mx_idx;k+=lowbit(k))ret+=c[k];
		return ret;
	}
};
BIT<int>t[3];
int m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		const int ex=n+1;
		for(ri i=0;i<3;++i)t[i].mx_idx=n+ex,t[i].clear();
		t[0].add(0+ex,1);
		ll ans=0;
		for(ri i=1,pre=0;i<=n;++i){
			pre+=(s[i]=='+'?1:-1);
			ri pos=(pre%3+3)%3;
			ans+=t[pos].query(pre+ex);
			t[pos].add(pre+ex,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}