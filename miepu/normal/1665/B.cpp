#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	map<int,int> a;
	int n,mx=0;
	cin>>n
;for(int i=1;i<=n;i++){
	int x;cin>>x;a[x]++;
	mx=max(mx,a[x]);
}
	int t=ceil(log2(1.*n/mx));
	int p=n-mx;
	cout<<t+p<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}