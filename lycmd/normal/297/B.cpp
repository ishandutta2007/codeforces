#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int n,m,k,a[N],b[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	if(n>m)
		cout<<"YES\n",exit(0);
	for(int i=1;i<=n;i++)
		if(a[n-i+1]>b[m-i+1])
			cout<<"YES\n",exit(0);
	cout<<"NO\n";
}