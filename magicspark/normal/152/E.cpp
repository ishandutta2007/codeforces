#include<bits/stdc++.h>
#define turn(x,y) (x*m+y)
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
//state:(2^k)*(n*m)
int n,m,k;
int dp[101][101][131],pre[101][101][131][3];
int dist[202][202];
int a[101][101];
string ans[202];
int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
void calc(int x,int y){
	dist[turn(x,y)][turn(x,y)]=a[x][y];
	set<pair<int,int> >st;
	st.insert(make_pair(a[x][y],turn(x,y)));
	while(st.begin()!=st.end()){
		int cur=st.begin()->second,cos=st.begin()->first;
		st.erase(st.begin());
		if(dist[turn(x,y)][cur]!=cos)continue;
		int nx=cur/m,ny=cur%m;
		for(int i=0;i<4;i++){
			int tx=nx+dx[i],ty=ny+dy[i];
			if(tx<0||ty<0||tx>=n||ty>=m||dist[turn(x,y)][turn(tx,ty)]<=dist[turn(x,y)][turn(nx,ny)]+a[tx][ty])continue;
			dist[turn(x,y)][turn(tx,ty)]=dist[turn(x,y)][turn(nx,ny)]+a[tx][ty];
			st.insert(make_pair(dist[turn(x,y)][turn(tx,ty)],turn(tx,ty)));
		}
	}
}
int getdist(int x1,int y1,int x2,int y2){
	return dist[x1*m+y1][x2*m+y2];
}
void print(int x,int y,int mask){
//	cerr<<x<<" "<<y<<" "<<mask<<" "<<pre[x][y][mask][0]<<endl; 
	ans[x][y]='X';
	if(pre[x][y][mask][0]==0)print(pre[x][y][mask][1],pre[x][y][mask][2],mask);
	else if(pre[x][y][mask][0]==1)print(x,y,pre[x][y][mask][1]),print(x,y,pre[x][y][mask][2]);
}
int main(){
	memset(pre,inf,sizeof(pre));
	memset(dist,inf,sizeof(dist));
	memset(dp,inf,sizeof(dp));
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)calc(i,j),ans[i].push_back('.');
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;x--;y--;
		dp[x][y][1<<i]=a[x][y];
	}
	for(int iter=0;iter<=222;iter++)
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(int mask=0;mask<(1<<k);mask++){
				for(int sub=mask;sub;sub=sub-1&mask){
					int v=dp[i][j][sub]+dp[i][j][mask^sub]-a[i][j];
					if(v<dp[i][j][mask])dp[i][j][mask]=v,pre[i][j][mask][0]=1,pre[i][j][mask][1]=sub,pre[i][j][mask][2]=mask^sub;
				}
				
				for(int k=0;k<4;k++){
					int x=i+dx[k],y=j+dy[k];if(x<0||y<0||x>=n||y>=m)continue;
					if(dp[x][y][mask]+getdist(i,j,x,y)-a[x][y]<dp[i][j][mask])dp[i][j][mask]=dp[x][y][mask]+getdist(i,j,x,y)-a[x][y],pre[i][j][mask][0]=0,pre[i][j][mask][1]=x,pre[i][j][mask][2]=y;
				}
			}
	int ansv=inf;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)ansv=min(ansv,dp[i][j][(1<<k)-1]);
	cout<<ansv<<endl;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(dp[i][j][(1<<k)-1]==ansv){print(i,j,(1<<k)-1);for(int i=0;i<n;i++)cout<<ans[i]<<endl;return 0;}
	return 0;
}