#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2010,MOD=1000000007;
int t,n,m;
char a[N][N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		int ans=1,flg=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j],ans=ans*(1+a[i][j]%2)%MOD,flg&=a[i][j]%2;
		cout<<(ans-flg+MOD)%MOD<<"\n";
	}
}