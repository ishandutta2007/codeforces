#include<bits/stdc++.h>
using namespace std;
int const N=2010;
int n,m,q,a[N][N],vis[N][N];
int solve(int x,int y,int d){
	for(int i=max(1,x-d);i<=min(n,x+d);i++){
		int k=d-abs(i-x);
		if(y-k>=1&&!vis[i][y-k])
			return cout<<i<<" "<<y-k<<"\n",vis[i][y-k]=1;
		if(y+k<=m&&!vis[i][y+k])
			return cout<<i<<" "<<y+k<<"\n",vis[i][y+k]=1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m>>q;q--;){
		int x,y;cin>>x>>y;
		for(int i=x-2;i<=x+2;i++)
			for(int j=y-2;j<=y+2;j++)
				if(1<=i&&i<=n&&1<=j&&j<=m)
					a[x][y]=max(a[x][y],a[i][j]-abs(x-i)-abs(y-j));
		while(!solve(x,y,a[x][y]))a[x][y]++;
	}
}