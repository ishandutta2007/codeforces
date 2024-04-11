#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	int mn=1e18,mx=0,x;
	for(int i=1;i<=n;i++)cin>>x,mn=min(mn,x),mx=max(mx,x);
	cout<<mx-mn<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}