#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333;
int t,n,a[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,max((i>1?a[i-1]-a[i]:0),max(a[i]-a[1],a[n]-a[i])));
		cout<<ans<<"\n";
	}
	return 0;
}