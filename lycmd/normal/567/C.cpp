#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,k,ans,a[N];
map<int,vector<int> >p;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[a[i]].push_back(i);
	for(int i=1;i<=n;i++){
		if(a[i]%k)
			continue;
		int a1=a[i]/k,a3=a[i]*k;
		ans+=1ll*(upper_bound(p[a1].begin(),p[a1].end(),i-1)-p[a1].begin())*
			(p[a3].end()-upper_bound(p[a3].begin(),p[a3].end(),i));
	}
	cout<<ans<<"\n";
}