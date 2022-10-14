#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333333;
int n,m,k,a[N],f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=0,p=0;i<=n;i++)
		if(f[i])
			for(p=max(p,i+k);p<=n&&a[p]-a[i+1]<=m;)
				f[p++]=1;
	cout<<(f[n]?"YES\n":"NO\n");
}