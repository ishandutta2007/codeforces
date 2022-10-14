#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2e5+5;
int t,n,a[N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0,l=a[1],r=-a[n];
		for(int i=1,x;i<n;i++){
			x=a[i+1]-a[i];
			if(x<0)l+=x,ans-=x;
			else r-=x,ans+=x;
		}
		cout<<ans+abs(l)<<"\n";
	}
}