#include <bits/stdc++.h>
using namespace std;
#define N 3005
#define ll long long
int T,n,a[N],pr[N][N],sf[N][N];ll ans;
void slv()
{
	ans=0;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<=n;++j) pr[i][j]=pr[i-1][j];
		++pr[i][a[i]];
	}
	for(int i=n;i>=1;--i)
	{
		for(int j=1;j<=n;++j) sf[i][j]=sf[i+1][j];
		++sf[i][a[i]];
	}
	for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j)
		ans+=1ll*pr[i-1][a[j]]*sf[j+1][a[i]];
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}