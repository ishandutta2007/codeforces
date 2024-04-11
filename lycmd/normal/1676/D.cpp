#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233;
int t,n,m,a[N][N],s1[N][N],s2[N][N],s3[N][N],s4[N][N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=0;i<=n+1;i++)
			s1[i][0]=s2[i][0]=s3[i][0]=s4[i][0]=
			s1[i][m+1]=s2[i][m+1]=s3[i][m+1]=s4[i][m+1]=0;
		for(int i=0;i<=m+1;i++)
			s1[0][i]=s2[0][i]=s3[0][i]=s4[0][i]=
			s1[n+1][i]=s2[n+1][i]=s3[n+1][i]=s4[n+1][i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				s1[i][j]=s1[i-1][j-1]+a[i][j],
				s2[i][j]=s2[i-1][j+1]+a[i][j];
		for(int i=n;i>=1;i--)
			for(int j=m;j>=1;j--)
				s3[i][j]=s3[i+1][j+1]+a[i][j],
				s4[i][j]=s4[i+1][j-1]+a[i][j];
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans=max(ans,s1[i][j]+s2[i][j]+s3[i][j]+s4[i][j]-3*a[i][j]);
		cout<<ans<<"\n";
	}
	return 0;
}