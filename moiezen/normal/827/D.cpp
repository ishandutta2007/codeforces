#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define N 200005
int n,m,fa[N],leg[N];int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
struct edge{int x,y,z,id;}a[N];bool operator<(edge a,edge b){return a.z<b.z;}
std::vector<std::pair<int,int> > e[N];
int dep[N],pre[N][18],mx[N][18],mn[N][18];
int ans[N];
void dfs(int x){
	rep(i,1,e[x].size()){
		int y=e[x][i-1].first;
		if(y==pre[x][0]) continue;
		dep[y]=dep[x]+1;
		pre[y][0]=x;
		mx[y][0]=e[x][i-1].second;
		dfs(y);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) std::swap(x,y);
	int k=dep[x]-dep[y];
	rep(i,0,17) if(k>>i&1) x=pre[x][i];
	if(x==y) return x;
	per(i,17,0) if(pre[x][i]!=pre[y][i]) x=pre[x][i],y=pre[y][i];
	return pre[x][0];
}
int um(int x,int d){
	int s=0;
	rep(i,0,17) if(d>>i&1) s=std::max(s,mx[x][i]),x=pre[x][i];
	return s;
}
int cm(int x,int y){
	int z=lca(x,y);
	return std::max(um(x,dep[x]-dep[z]),um(y,dep[y]-dep[z]));
}
void ud(int x,int d,int v){
	rep(i,0,17) if(d>>i&1) mn[x][i]=std::min(mn[x][i],v),x=pre[x][i];
}
void cd(int x,int y,int v){
	int z=lca(x,y);
	ud(x,dep[x]-dep[z],v);
	ud(y,dep[y]-dep[z],v);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].id=i,leg[i]=0;
	std::sort(a+1,a+m+1);
	rep(i,1,n) fa[i]=i,e[i].clear();
	rep(i,1,m){
		int u=father(a[i].x),v=father(a[i].y);
		if(u==v) continue;
		fa[u]=v;leg[i]=1;
		e[a[i].x].push_back(std::make_pair(a[i].y,a[i].z));
		e[a[i].y].push_back(std::make_pair(a[i].x,a[i].z));
	}
	dep[1]=pre[1][0]=0;dfs(1);
	rep(k,1,17) rep(i,1,n){
		if(pre[i][k-1]) pre[i][k]=pre[pre[i][k-1]][k-1];else pre[i][k]=0;
		if(pre[i][k]) mx[i][k]=std::max(mx[i][k-1],mx[pre[i][k-1]][k-1]);
	}
	rep(i,1,n) rep(j,0,17) mn[i][j]=1<<30;
	rep(i,1,m) if(!leg[i]){
		ans[a[i].id]=cm(a[i].x,a[i].y)-1;
		cd(a[i].x,a[i].y,a[i].z);
	}
	per(k,17,1) rep(i,1,n){
		mn[i][k-1]=std::min(mn[i][k-1],mn[i][k]);
		mn[pre[i][k-1]][k-1]=std::min(mn[pre[i][k-1]][k-1],mn[i][k]);
	}
	rep(i,1,m) if(leg[i]){
		if(pre[a[i].x][0]!=a[i].y) std::swap(a[i].x,a[i].y);
		ans[a[i].id]=mn[a[i].x][0]-1;
	}
	rep(i,1,m) printf("%d ",ans[i]>1000000007?-1:ans[i]);
}