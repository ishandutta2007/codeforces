#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=55;
int t,n,a[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		int mn=INT_MAX,s=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],s+=a[i],mn=min(mn,a[i]);
		cout<<s-mn*n<<"\n";
	}
	return 0;
}