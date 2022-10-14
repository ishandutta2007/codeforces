#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1010;
int n,m,ans,a[N][N],ul[N][N],ur[N][N],dl[N][N],dr[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ul[i][j]=a[i][j]+max(ul[i-1][j],ul[i][j-1]);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			ur[i][j]=a[i][j]+max(ur[i-1][j],ur[i][j+1]);
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			dl[i][j]=a[i][j]+max(dl[i+1][j],dl[i][j-1]);
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
			dr[i][j]=a[i][j]+max(dr[i+1][j],dr[i][j+1]);
	for(int i=2;i<n;i++)
		for(int j=2;j<m;j++)
			ans=max(ans,
				max(ul[i-1][j]+ur[i][j+1]+dr[i+1][j]+dl[i][j-1],
					ur[i-1][j]+dr[i][j+1]+dl[i+1][j]+ul[i][j-1]));
	cout<<ans<<"\n";
}