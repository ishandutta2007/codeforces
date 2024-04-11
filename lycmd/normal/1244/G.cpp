#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010;
int n,k,ans,a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k,ans=n*(n+1)/2;
	if(k<ans)cout<<"-1\n",exit(0);
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1,j=n;i<j;i++)
		if(ans+j-i<=k)
			ans+=j-i,swap(a[i],a[j--]);
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
		cout<<i<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" "; 
}