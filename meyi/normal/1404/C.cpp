#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=3e5+10;
int a[maxn],ans[maxn],m,n,t_case;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>q[maxn];
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
	inline int half(int k){
		ri now=0,sum=0;
		for(ri i=1<<18;i;i>>=1){
			ri nxt=now|i;
			if(nxt<=k&&sum+c[nxt]>=a[k])now=nxt,sum+=c[nxt];
		}
		return now+1;
	}
};
BIT<int>t;
int main(){
	scanf("%d%d",&n,&m);
	t.mx_idx=n;
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		a[i]=i-a[i];
	}
	for(ri i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		q[n-y].emplace_back(x+1,i);
	}
	for(ri i=1;i<=n;++i){
		if(a[i]>=0){
			ri pos=t.half(i);
			if(pos>1)t.add(1,1),t.add(pos,-1);
		}
		for(const pii &j:q[i])ans[j.se]=t.query(j.fi);
	}
	for(ri i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}