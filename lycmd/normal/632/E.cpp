#include<bits/stdc++.h>
using namespace std;
int const N=1010,M=1000010;
int n,k,a[N],f[M];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		a[i]-=a[1];
	memset(f,0x3f,sizeof f),f[0]=0;
	int t=a[n]*k;
	for(int i=2;i<=n;i++)
		for(int j=a[i];j<=t;j++)
			f[j]=min(f[j],f[j-a[i]]+1);
	for(int i=0;i<=t;i++)
		if(f[i]<=k)
			cout<<k*a[1]+i<<" ";
	cout<<"\n";
}