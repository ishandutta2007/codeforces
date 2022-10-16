#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,mx=0,res=0;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		mx=max(mx,x);
		res+=mx==i;
	}cout<<res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}