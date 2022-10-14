#include<bits/stdc++.h>
using namespace std;
int const N=233;
int n,m,f[N][N][28];
basic_string<int>e[N],c[N];
inline int dfs(int x,int y,int p){
	if(~f[x][y][p])
		return f[x][y][p];
	for(int i=0;i<e[x].size();i++)
		if(c[x][i]>=p){
			if(!dfs(y,e[x][i],c[x][i]))
				return f[x][y][p]=1;
		}
	return f[x][y][p]=0;
}
int main(){  
	ios::sync_with_stdio(0);
	cin>>n>>m;
	while(m--){
		int x,y;char op;
		cin>>x>>y>>op;
		e[x]+=y,c[x]+=op-97;
	}
	memset(f,-1,sizeof f);
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=n;j++)
			cout<<(dfs(i,j,0)?"A":"B");
	return 0;
}