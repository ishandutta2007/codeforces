#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=1000000007;
int t,n;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		int ans=1;
		for(int i=3;i<=2*n;i++)
			ans=ans*i%MOD;
		cout<<ans<<"\n";
	}
}//