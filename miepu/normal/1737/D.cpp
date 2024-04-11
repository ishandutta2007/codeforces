#include<bits/stdc++.h>
#define int long long
const int N=505;
using namespace std;

int n,m;
int dis[N][N];

struct node{
	int x,y,w;
};

void solve(){
	memset(dis,1,sizeof(dis));
	cin>>n>>m;
	vector<node> A;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		A.push_back({x,y,z});
		dis[x][y]=dis[y][x]=1;
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	int res=1e18;
	for(auto x:A){
		int d=1e9;
		d=min(dis[x.x][1]+dis[x.y][n],d);
		d=min(dis[x.y][1]+dis[x.x][n],d);
		for(int i=1;i<=n;i++){
			d=min(dis[i][1]+dis[i][n]+dis[i][x.x]+1,d);
			d=min(dis[i][1]+dis[i][n]+dis[i][x.y]+1,d);
		}
		res=min(res,(d+1)*x.w);
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}