#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	if(r1<l2||l1>r2)cout<<l1+l2<<endl;
	else cout<<max(l1,l2)<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}