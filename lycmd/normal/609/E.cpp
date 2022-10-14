#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=400010,B=22;
int n,m,sum,f[N],fa[N][B],mx[N][B],ans[N],dep[N],vis[N];
struct edge{
	int x,y,w,id;
	int operator<(const edge&rhs)const{
		return w<rhs.w;
	}
};
vector<edge>k;
vector<pair<int,int> >e[N];
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
void dfs(int x,int pre){
	dep[x]=dep[pre]+1;
	for(int i=1;fa[fa[x][i-1]][i-1];i++){
		int y=fa[x][i-1];
		fa[x][i]=fa[y][i-1];
		mx[x][i]=max(mx[x][i-1],mx[y][i-1]);
	}
	for(auto i:e[x]){
		int y=i.first,k=i.second;
		if(y==pre)continue;
		mx[y][0]=k,dfs(y,fa[y][0]=x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=B-1;~i;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for(int i=B-1;~i;i--)
		if(fa[x][i]^fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int jump(int x,int y){
	int res=0;
	for(int i=B-1;~i;i--)
		if(dep[fa[x][i]]>=dep[y])
			res=max(res,mx[x][i]),x=fa[x][i];
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;      
		k.push_back({a,b,c,i});
	}
	sort(k.begin(),k.end());
	for(int i=0;i<m;i++){
		int x=k[i].x,y=k[i].y,w=k[i].w;
		if(!merge(x,y))continue;
		e[x].push_back({y,w});
		e[y].push_back({x,w});
		sum+=w,vis[k[i].id]=1;
	}
	dfs(1,0);
	for(int i=0;i<m;i++){
		if(vis[k[i].id]){
			ans[k[i].id]=sum;
			continue;
		}
		int x=k[i].x,y=k[i].y,a=lca(x,y);
		ans[k[i].id]=sum+k[i].w-max(jump(x,a),jump(y,a));
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<"\n";
}