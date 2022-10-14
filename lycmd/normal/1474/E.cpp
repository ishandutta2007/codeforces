#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		int ans=0;
		for(int i=3;i<=n+1;i++)
			ans+=(n-i/2)*(n-i/2);
		cout<<ans<<"\n"<<n/2+1;
		for(int i=1;i<=n;i++)
			if(i<n/2||i>n/2+1)
				cout<<" "<<i;
		cout<<" "<<n/2<<"\n"<<n-1<<"\n";
		for(int i=n/2;i>1;i--)
			cout<<i<<" "<<n<<"\n";
		for(int i=n/2+1;i<=n;i++)
			cout<<i<<" 1\n";
	}
}