#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int F(int n,int a){
	return n/a+n%a;
}

void solve(){
	int l,r,a;cin>>l>>r>>a;
	int k=(r+1)/a*a-1;
	k=max(k,l);
	cout<<max({F(l,a),F(k,a),F(r,a)})<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}