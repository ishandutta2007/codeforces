#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,m;
	int x,y;int mx=-1e18;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int z;cin>>z;
			if(z>mx)mx=z,x=i,y=j;
		}
	}
	cout<<max(x,n-x+1)*max(y,m-y+1)<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}