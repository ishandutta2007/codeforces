#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=505;
int t,n,a[N][N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=2*n;i++)
			for(int j=1;j<=2*n;j++)
				cin>>a[i][j];
		int ans=min(min(min(a[n+1][1],a[n+1][n]),min(a[2*n][1],a[2*n][n]))
				   ,min(min(a[1][n+1],a[n][n+1]),min(a[1][2*n],a[n][2*n])));
		for(int i=n+1;i<=2*n;i++)
			for(int j=n+1;j<=2*n;j++)
				ans+=a[i][j];
		cout<<ans<<"\n";
	}
}