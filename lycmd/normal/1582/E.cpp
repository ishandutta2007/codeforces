#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,K=505,INF=0x3f3f3f3f3f3f3f3fll;
int t,n,a[N],s[N],f[N][K];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=n;i>=1;i--)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		for(int i=0;i<=n;i++)
			for(int j=0;j*j<=2*n;j++)
				f[i][j]=j?0:INF;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i&&j*j<=2*n;j++)
				f[i][j]=max(f[i-1][j],s[i]-s[i-j]<f[i-j][j-1]?
					s[i]-s[i-j]:-INF);
		for(int i=K-1;;i--)
			if(f[n][i]){
				cout<<i<<"\n";
				break;
			}
	}
}