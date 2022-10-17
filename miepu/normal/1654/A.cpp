#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(auto&x:a)cin>>x;
	sort(a.begin(),a.end()); 
	reverse(a.begin(),a.end()); 
	cout<<a[0]+a[1]<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}