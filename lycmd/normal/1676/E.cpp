#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,q,a[N],s[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>q;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		while(q--){
			int x;cin>>x;
			cout<<(s[n]<x?-1:lower_bound(s+1,s+1+n,x)-s)<<"\n";
		}
	}
	return 0;
}