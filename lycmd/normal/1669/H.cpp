#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int t,n,k,a[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=30;~i;i--){
			int cnt=0;
			for(int j=1;j<=n;j++)
				cnt+=~a[j]>>i&1;
			if(k>=cnt)k-=cnt,ans|=1ll<<i; 
		}
		cout<<ans<<"\n";
	}
	return 0;
}