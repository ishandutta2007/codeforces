#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5010;
int n,cnt,a[N],b[N],f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]&&(b[++cnt]=i);
	memset(f,0x3f,sizeof f);
	for(int i=0;i<=n;i++)
		f[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=cnt;j++)
			f[i][j]=a[i]?f[i-1][j]:min(f[i-1][j],f[i-1][j-1]+abs(i-b[j]));
	cout<<f[n][cnt]<<"\n";
}