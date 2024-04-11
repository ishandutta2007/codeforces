#include<bits/stdc++.h>
using namespace std;
int const N=55,M=2505,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,ans=M,tot,c[N][N],f[M],g[M][M],d[M];
char a[N][N];
vector<int>e[M];
void dfs(int x,int y,int col){
	c[x][y]=col;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<1||ty<1||tx>n||ty>m||c[tx][ty]||a[x][y]^a[tx][ty])
			continue;
		dfs(tx,ty,col);
	}
}
int bfs(int x){
	queue<int>q;
	memset(d,0x3f,sizeof d),d[x]=0,q.push(x);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:e[x])
			if(d[y]>d[x]+1)
				d[y]=d[x]+1,q.push(y);
	}
	int res=0;
	for(int i=1;i<=tot;i++)
		if(f[i])res=max(res,d[i]);
	return res+1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!c[i][j])
				dfs(i,j,++tot),f[tot]=a[i][j]=='B';
	if(tot==1&&!f[1])
		cout<<"0\n",exit(0);
	for(int x=1;x<=n;x++)
		for(int y=1;y<=m;y++)
			for(int i=0;i<4;i++){
				int tx=x+dx[i],ty=y+dy[i];
				if(tx<1||ty<1||tx>n||ty>m||c[x][y]==c[tx][ty])
					continue;
				g[c[x][y]][c[tx][ty]]=1;
			}
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=tot;j++)
			if(g[i][j])
				e[i].push_back(j);
	for(int i=1;i<=tot;i++)
		ans=min(ans,bfs(i));
	cout<<ans<<"\n";
}