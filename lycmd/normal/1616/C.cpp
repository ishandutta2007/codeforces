#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,a[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=n==1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int t=0;
				double d=1.0*(a[j]-a[i])/(j-i);
				for(int p=1;p<=n;p++)
					t+=fabs(a[p]-a[i]-(p-i)*d)<1e-8;
				ans=max(ans,t);
			}
		cout<<n-ans<<"\n";
	}
	return 0;
}