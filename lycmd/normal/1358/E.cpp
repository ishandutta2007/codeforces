#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=500010;
int n,p,k,s[N],a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,p=(n+1)/2;
	for(int i=1;i<=p;i++)
		cin>>a[i];
	cin>>k;
	for(int i=p+1;i<=n;i++)
		a[i]=k;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	if(k>=0)
		cout<<(s[n]>0?n:-1)<<"\n",exit(0);
	int mx=n;
	for(int i=1;i<=p;i++){
		if(s[p]-s[i-1]<=0)
			cout<<"-1\n",exit(0);
		mx=min(mx,min((s[p]-s[i-1]-1)/-k+p,n)-i+1);
		if(n-i+1<=mx)
			cout<<n-i+1<<"\n",exit(0);
	}
	cout<<"-1\n";
}