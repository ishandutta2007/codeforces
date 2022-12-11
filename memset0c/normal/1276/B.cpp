#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=5e5+10;
int s,n,m,x,y,t,l=1,r,cnt1,cnt2,fa[N],q[N],vis[N];
std::vector<int> G[N],T[N];
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int u){
	// printf("dfs %d\n",u);
	for(int v:T[u])if(v!=fa[u]){
		fa[v]=u,dfs(v);
	}
}
void dfs2(int u){
	// printf("dfs2 %d\n",u);
	q[++r]=u;
	for(int v:T[u])if(v!=fa[u]){
		fa[v]=u,dfs2(v);
	}
}
void bfs(int rt){
	while(l<=r){
		int u=q[l++];
		for(int v:G[u])if(v!=rt&&!vis[v]){
			vis[v]=1,q[++r]=v;
		}
	}
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(s);s--;){
		read(n),read(m),read(x),read(y),cnt1=cnt2=0;
		for(int i=1;i<=n;i++)fa[i]=i,G[i].clear(),T[i].clear();
		for(int u,v,i=1;i<=m;i++){
			read(u),read(v);
			G[u].push_back(v),G[v].push_back(u);
			if(find(u)!=find(v)){
				T[u].push_back(v),T[v].push_back(u);
				fa[find(u)]=find(v);
			}
		}
		fa[x]=0,dfs(x),t=y;while(fa[t]!=x)t=fa[t];l=1,r=0,dfs2(t),bfs(x);
		for(int i=1;i<=n;i++)if(!vis[i])++cnt1;memset(vis+1,0,n<<2);
		fa[y]=0,dfs(y),t=x;while(fa[t]!=y)t=fa[t];l=1,r=0,dfs2(t),bfs(y);
		for(int i=1;i<=n;i++)if(!vis[i])++cnt2;memset(vis+1,0,n<<2);
		printf("%lld\n",(long long)(cnt1-1)*(cnt2-1));
	}
}