#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,m,p=1,a[N],f[N],cnt[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]<=m&&++cnt[a[i]];
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j+=i)
			f[j]+=cnt[i];
	for(int i=1;i<=m;i++)
		if(f[i]>f[p])p=i;
	cout<<p<<" "<<f[p]<<"\n";
	for(int i=1;i<=n;i++)
		if(p%a[i]==0)
			cout<<i<<" ";
	cout<<"\n";
}