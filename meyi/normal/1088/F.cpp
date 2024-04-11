#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],fa[maxn][20],rt;
inline int ptmin(const int &x,const int &y){return a[x]<a[y]?x:y;}
ll ans;
void dfs(int p,int f){
	if(f){
		fa[p][0]=f;
		ll tmp=a[f]+a[p];
		for(ri i=1;i<20;++i){
			fa[p][i]=fa[fa[p][i-1]][i-1];
			ckmin(tmp,a[fa[p][i]]+a[p]+1ll*i*a[fa[p][i]]);
		}
		ans+=tmp;
	}
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs(e[i].to,p);
}
int n;
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	rt=min_element(a+1,a+n+1)-a;
	for(ri i=0;i<20;++i)fa[rt][i]=rt;
	dfs(rt,0);
	printf("%lld",ans);
	return 0;
}