#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,k,s=0;cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) 
		cin>>a[i],s+=a[i];
	sort(a.begin(),a.end());
	int ans=s-k;
	for(int j=n-1,ns=0,cnt=1;j;j--){
		ns+=a[j]-a[0];cnt++;
		int na=max(ceil(1.*(s-k-ns)/cnt),.0)+cnt-1;
		ans=min(na,ans);
	}
	cout<<max(ans,0ll)<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}