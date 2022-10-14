#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[25][25],ans;
map<int,int>s[25][25];
void dfs1(int x,int y,int sum1){
	if(x>n||y>m)return;
	if(x+y==(n+m)/2+1){
		++s[x][y][sum1];
		return;
	}
	dfs1(x+1,y,a[x+1][y]^sum1);
	dfs1(x,y+1,a[x][y+1]^sum1);
}
void dfs2(int x,int y,int sum2){
	if(x<1||y<1)return;
	if(x+y==(n+m)/2+1){
		ans+=s[x][y][sum2^k^a[x][y]];
		return;
	}
	dfs2(x-1,y,a[x-1][y]^sum2);
	dfs2(x,y-1,a[x][y-1]^sum2);
}
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)cin>>a[i][j];
	dfs1(1,1,a[1][1]);
	dfs2(n,m,a[n][m]);
	cout<<ans<<"\n";
}