#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	int s=0;
	for(auto&x:a){
		cin>>x;
		s+=x;
	}
	for(auto x:a){
		if(x*n==s){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}