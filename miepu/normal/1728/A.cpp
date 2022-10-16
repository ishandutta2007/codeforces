#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int res=0,mx=-1;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x>mx){
			res=i;
			mx=x;
		}
	}
	cout<<res<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}