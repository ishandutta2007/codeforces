#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2010,INF=0x3f3f3f3f;
int n,m,a[N],f[N][N];
int check(int k){
	memset(f,INF,sizeof f),f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++){
			f[i][j]=f[i-1][j-1]+1;
			if(i-j<2||abs(a[i]-a[i-j-1])<=(j+1)*k)
				f[i][0]=min(f[i][0],f[i-1][j]);
		}
	int res=INF;
	for(int i=0;i<=n;i++)
		res=min(res,f[n][i]);
	return res<=m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=-1,r=3e9;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<r<<"\n";
}