#include<bits/stdc++.h>
using namespace std;
int const N=7010;
string const sta[]={"Lose","Loop","Win"};
int n,k[2],s[2][N],f[2][N],c[2][N];
void dfs(int x,int p,int cur){
	if(f[x][p])return;
	f[x][p]=cur;
	int y=!x;
	for(int i=1;i<=k[y];i++){
		int q=(p-s[y][i]+n-1)%n+1;
		if(q==1)continue;
		if(!~cur)dfs(y,q,1);
		else if(++c[y][q]==k[y])dfs(y,q,-1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<2;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>s[i][j];
	}
	dfs(0,1,-1),dfs(1,1,-1);
	for(int i=0;i<2;i++,cout<<"\n")
		for(int j=2;j<=n;j++)
			cout<<sta[f[i][j]+1]<<" ";
}