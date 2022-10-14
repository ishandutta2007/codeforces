#include<bits/stdc++.h>
using namespace std;
int const N=233333,INF=0x3f3f3f3f;
int t,n,f[N][2],pre[N][2],fa[N];
vector<int>e[N],g[N];
struct node{
	int x,y;
	node operator+(const node&rhs)const{
		return{x,rhs.y};
	}
};
node s[N];
int find(int x){
	return x^fa[x]?fa[x]=find(fa[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(fa[fx]=fy,s[fy]=s[fx]+s[fy],1):0;
}
void dfs(int x,int fa){
	if(e[x].size()==1&&x>1){
		f[x][0]=f[x][1]=0;
		return;
	}
	int s=e[x].size()-(x>1);
	for(int y:e[x])
		if(y^fa)
			dfs(y,x),s+=f[y][1];
	for(int y:e[x])
		if(y^fa)
			if(s-f[y][1]-1+f[y][0]<f[x][0])
				f[x][0]=s-f[y][1]-1+f[y][0],pre[x][0]=y;
	f[x][1]=f[x][0];
	for(int y:e[x])
		if(y^fa&&y^pre[x][0])
			if(f[x][0]-f[y][1]-1+f[y][0]<f[x][1])
				f[x][1]=f[x][0]-f[y][1]-1+f[y][0],pre[x][1]=y;
}
void build(int x,int fa,int flg){
	if(pre[x][0])
		g[x].push_back(pre[x][0]),g[pre[x][0]].push_back(x),
		build(pre[x][0],x,0);
	if(flg&&pre[x][1])
		g[x].push_back(pre[x][1]),g[pre[x][1]].push_back(x),
		build(pre[x][1],x,0);
	for(int y:e[x])
		if(y^fa&&y^pre[x][0]&&(!flg||y^pre[x][1]))
			build(y,x,1);
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			f[i][0]=f[i][1]=INF,pre[i][0]=pre[i][1]=fa[i]=0,
			e[i].clear(),g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)
			s[i].x=s[i].y=fa[i]=i;
		cout<<f[1][1]<<"\n";
		build(1,0,1);
		for(int i=1;i<=n;i++)
			if(g[i].size()==1)
				for(int j=g[i][0],pre=i,t;;t=pre,pre=j,j=g[j][g[j][0]==t]){
					merge(pre,j);
					if(g[j].size()==1)
						break;
				}
		for(int x=1;x<=n;x++)
			for(int y:e[x])
				if(find(x)!=find(y))
					cout<<x<<" "<<y<<" "<<s[find(x)].y
						<<" "<<s[find(y)].x<<"\n",merge(x,y);
	}
}