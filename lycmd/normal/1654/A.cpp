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
		sort(a+1,a+1+n);
		cout<<a[n]+a[n-1]<<"\n";
	}
	return 0;
}