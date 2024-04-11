#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int ans[maxn],n;
void dfs(int p,int k){
	ans[p]=k;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!ans[e[i].to])
			dfs(e[i].to,3-k);
}
int x[maxn],y[maxn];
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d%d",x+i,y+i);
		addedge(x[i],y[i]),addedge(y[i],x[i]);
	}
	for(ri i=1;i<=n;++i)addedge((i<<1)-1,i<<1),addedge(i<<1,(i<<1)-1);
	for(ri i=1;i<=(n<<1);++i)if(!ans[i])dfs(i,1);
	for(ri i=1;i<=n;++i)printf("%d %d\n",ans[x[i]],ans[y[i]]);
	return 0;
}