#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int res=0;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		res|=x;
	}
	cout<<res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}