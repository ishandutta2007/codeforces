#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=1e5+10;
int n,m,fa[N],dep[N],siz[N],nod[N],anc[N],jump[N][20];
long long ans,sub[N],all[N];
std::vector<int> G[N];
int find(int x){return anc[x]==x?x:anc[x]=find(anc[x]);}
long long C2(int n){return (long long)n*(n-1)/2;}
long long C3(int n){return (long long)n*(n-1)*(n-2)/6;}
inline int lca(int u,int v){
	if(dep[u]>dep[v])std::swap(u,v);
	for(int i=19;i>=0;i--)if(dep[jump[v][i]]>=dep[u])v=jump[v][i];
	if(u==v)return u;
	for(int i=19;i>=0;i--)if(jump[u][i]!=jump[v][i])u=jump[u][i],v=jump[v][i];
	return fa[u];
}
void dfs(int u){
	siz[u]=1;
	for(int v:G[u])if(v!=fa[u]){
		fa[v]=u,dep[v]=dep[u]+1;
		dfs(v);
		siz[u]+=siz[v];
	}
}
void merge(int x,int y,int sx,int sy){
	// printf("merge %d[%d %lld %lld] %d[%d %lld %lld] %d %d\n",x,nod[x],sub[x],all[x],y,nod[y],sub[y],all[y],sx,sy);
	ans-=all[x]+all[y];
	anc[x]=y;
	nod[y]+=nod[x];
	sub[y]+=sub[x]-C2(sx)-C2(sy);
	ans+=all[y]=C3(nod[y])*3+(n-nod[y])*C2(nod[y])*2+nod[y]*(C2(n-nod[y])-sub[y]);
	// printf(">> %d %lld %lld : ans=%lld\n",nod[y],sub[y],all[y],ans);
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int u,v,i=1;i<n;i++){
		read(u),read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dep[1]=1,dfs(1);
	for(int i=1;i<=n;i++){
		anc[i]=i;
		nod[i]=1;
		sub[i]=C2(n-siz[i]);
		for(int j:G[i])if(j!=fa[i])sub[i]+=C2(siz[j]);
		ans+=all[i]=C2(n-1)-sub[i];
		jump[i][0]=fa[i];
	}
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			jump[j][i]=jump[jump[j][i-1]][i-1];
	print(ans<<1,'\n');
	read(m);
	for(int u,v,t,i=1;i<=m;i++){
		read(u),read(v),t=lca(u,v);
		// printf(">> u=%d v=%d t=%d\n",u,v,t);
		auto combine=[&](int u,int v){
			v=find(v);
			while(find(u)!=v){
				u=find(u);
				merge(u,find(fa[u]),n-siz[u],siz[u]);
				u=fa[u];
			}
		};
		combine(u,t);
		combine(v,t);
		print(ans<<1,'\n');
	}
}