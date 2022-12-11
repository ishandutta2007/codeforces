#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
const int N=3e5+10;
int n,m,nod,rt[N],dep[N];long long ans;
std::vector<int> G[N];std::vector<std::pair<int,int>> add[N];
struct node{int src,val,tag,dis,ch[2];}e[N];
inline void pushup(int u,int v){if(u)e[u].val+=v,e[u].tag+=v;}
inline void pushdown(int u){if(e[u].tag)pushup(e[u].ch[0],e[u].tag),pushup(e[u].ch[1],e[u].tag),e[u].tag=0;}
int merge(int x,int y){
	// printf("merge %d %d : %d\n",x,y,!x||!y);
	if(!x||!y)return x|y;pushdown(x),pushdown(y);
	if(e[x].val>e[y].val)std::swap(x,y);e[x].ch[1]=merge(e[x].ch[1],y);
	if(e[e[x].ch[0]].dis<e[e[x].ch[1]].dis)std::swap(e[x].ch[0],e[x].ch[1]);
	return e[x].dis=e[e[x].ch[0]].dis+1,x;
}
void dfs(int u,int fa){
	// printf("dfs %d %d %d\n",u,fa,rt[u]);
	// for(auto it:add[u])printf("> %d %d %d\n",u,it.first,it.second);
	for(int v:G[u])if(v!=fa)dep[v]=dep[u]+1,dfs(v,u),rt[u]=merge(rt[u],rt[v]);
	for(auto it:add[u])e[++nod]=(node){it.first,it.second,0,0,{0,0}},rt[u]=merge(rt[u],nod);
	while(rt[u]&&dep[e[rt[u]].src]>=dep[u])pushdown(rt[u]),rt[u]=merge(e[rt[u]].ch[0],e[rt[u]].ch[1]);
	if(rt[u])ans+=e[rt[u]].val,pushup(rt[u],-e[rt[u]].val);
	if(!rt[u]&&u!=1)puts("-1"),exit(0);
}
int main(){
	// freopen("1.in","r",stdin);
	read(n),read(m);
	for(int u,v,i=1;i<n;i++)read(u),read(v),G[u].push_back(v),G[v].push_back(u);
	for(int u,v,w,i=1;i<=m;i++)read(u),read(v),read(w),add[u].push_back(std::make_pair(v,w));
	dfs(1,0),printf("%lld\n",ans);
}