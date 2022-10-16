#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,x;cin>>n>>x;
	vector<int> a(n);
	for(auto&x:a)cin>>x;
	sort(a.begin(),a.end());
	vector<int> s(n+1);
	int res=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i-1];
		if(s[i]>x)break;
		res+=(x-s[i])/i+1;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}