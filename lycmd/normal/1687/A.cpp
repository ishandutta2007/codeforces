#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int t,n,k,a[N],s[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i],s[i]=s[i-1]+a[i];
		if(k<n){
			int res=0;
			for(int i=0;i<=n-k;i++)
				res=max(res,s[i+k]-s[i]+k*(k-1)/2);
			cout<<res<<"\n";
		}else cout<<s[n]+(2*k-1-n)*n/2<<"\n";
	}
}