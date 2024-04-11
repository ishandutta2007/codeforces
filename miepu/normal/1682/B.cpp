#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int res=~0;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(x!=i)res&=x;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}