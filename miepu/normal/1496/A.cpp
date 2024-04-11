#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	for(int i=0;i<k;i++){
		if(s[i]!=s[n-i-1]||k*2==n){
			cout<<"NO"<<endl;
			return;
		} 
	} 
	cout<<"YES"<<endl;
	
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}