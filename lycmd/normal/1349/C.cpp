#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1010,M=1000010,INF=0x3f3f3f3f3f3f3f3fll,
	dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,Q,tot,o[N][N],sz[M],d[M];
char a[N][N];
vector<int>e[M];
queue<int>q;
void dfs(int x,int y,int c){
	o[x][y]=c,sz[c]++;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(a[tx][ty]==a[x][y]&&!o[tx][ty])
			dfs(tx,ty,c);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!o[i][j])
				dfs(i,j,++tot);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int p=0;p<4;p++){
				int ti=i+dx[p],tj=j+dy[p];
				if(a[ti][tj]&48&&a[ti][tj]!=a[i][j])
					e[o[i][j]].push_back(o[ti][tj]);
			}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=tot;i++)
		if(sz[i]>1)
			q.push(i),d[i]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:e[x])
			if(d[y]==INF)
				d[y]=d[x]+1,q.push(y);
	}
	while(Q--){
		int x,y,t;cin>>x>>y>>t;
		cout<<((a[x][y]-48)^(max(0ll,t-d[o[x][y]])&1))<<"\n";
	}
}