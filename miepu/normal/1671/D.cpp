#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,x;cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int mx=0,mn=1e9,sum=0;
	for(int i=1;i<n;i++){
		sum+=abs(a[i-1]-a[i]);
	}
	for(int i=0;i<n;i++)
		mx=max(mx,a[i]),mn=min(mn,a[i]);
	int X=max(a[0],a[n-1]),I=min(a[0],a[n-1]);
	sum+=max(0ll,min(mn-1<<1,I-1));
	sum+=max(0ll,min(x-mx<<1,x-X));
	cout<<sum<<endl; 
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}