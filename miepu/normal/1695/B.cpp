#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	int mn=1e18,p=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x<mn)mn=x,p=i;
	}
	if(n&1){
		cout<<("Mike")<<endl;
	}else{
		cout<<((p&1)?"Joe":"Mike")<<endl;
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}