#include<bits/stdc++.h>
using namespace std;
int const N=2010,dx[]={-1,-1,1,1,-1,0,0,1},dy[]={-1,1,-1,1,0,-1,1,0};
int n,m,s[N][N];
char a[N][N];
int chk(int x,int y){
	if(a[x][y]!=42)return 0;
	for(int i=0;i<4;i++)
		if(a[x+dx[i]][y+dy[i]]==46&&a[x][y+dy[i]]==46
			&&a[x+dx[i]][y]==46)return 1;
	return 0;
}
void dfs(int x,int y){
	a[x][y]=46;
	for(int i=0;i<8;i++)
		if(chk(x+dx[i],y+dy[i]))
			dfs(x+dx[i],y+dy[i]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(chk(i,j))dfs(i,j);
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=m;j++)
			cout<<a[i][j];
}