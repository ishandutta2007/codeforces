#include<bits/stdc++.h>
using namespace std;
int const N=5010,M=505,K=100010;
int n,k,ans,a[N],p[N],h[N],cnt[K],pc[K],f[M][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n*k;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=n;i++)
		cin>>p[i],pc[p[i]]++;
	for(int i=1;i<=k;i++)
		cin>>h[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n*k;j++)
			for(int t=0;t<=min(j,k);t++)
				f[i][j]=max(f[i][j],f[i-1][j-t]+h[t]);
	for(int i=1;i<K;i++)
		ans+=f[pc[i]][cnt[i]];
	cout<<ans<<"\n";
}