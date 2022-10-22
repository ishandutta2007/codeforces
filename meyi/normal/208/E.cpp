#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
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
int dep[maxn],fa[maxn][17],lg;
void dfs1(int p){
	dep[p]=dep[fa[p][0]]+1;
	for(ri i=1;i<=lg;++i)fa[p][i]=fa[fa[p][i-1]][i-1];
	for(ri i=hd[p];i;i=e[i].nxt)dfs1(e[i].to);
}
int ans[maxn],cnt[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>q[maxn];
void dfs2(int p){
	for(auto i:q[p])ans[i.se]=-cnt[dep[p]+i.fi];
	++cnt[dep[p]];
	for(ri i=hd[p];i;i=e[i].nxt)dfs2(e[i].to);
	for(auto i:q[p])ans[i.se]+=cnt[dep[p]+i.fi];
}
int m,n;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",&fa[i][0]);
		if(fa[i][0])addedge(fa[i][0],i);
	}
	lg=__lg(n);
	for(ri i=1;i<=n;++i)
		if(!fa[i][0])
			dfs1(i);
	scanf("%d",&m);
	for(ri i=1;i<=m;++i){
		ri x,y;
		scanf("%d%d",&x,&y);
		for(ri i=lg;~i;--i)
			if(y&(1<<i))
				x=fa[x][i];
		q[x].emplace_back(y,i);
	}
	for(ri i=1;i<=n;++i)
		if(!fa[i][0])
			dfs2(i);
	for(ri i=1;i<=m;++i)printf("%d ",ans[i]?ans[i]-1:0);
	return 0;
}