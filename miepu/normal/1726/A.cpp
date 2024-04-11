#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int res=0;
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		res=max(res,a[i]-a[(i+1)%n]);
	}
	for(int i=1;i<n;i++){
		res=max(res,a[i]-a[0]);
	}
	for(int i=0;i<n-1;i++){
		res=max(res,a[n-1]-a[i]);
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}