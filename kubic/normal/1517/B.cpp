#include <bits/stdc++.h>
using namespace std;
#define N 105
#define ll long long
int T,n,m,L[N],R[N],a[N][N],ans[N][N];
void slv()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i) L[i]=1,R[i]=m,sort(a[i]+1,a[i]+m+1);
	for(int i=1,ps=0;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{if(!ps || a[j][L[j]]<a[ps][L[ps]]) ps=j;}
		for(int j=1;j<=n;++j)
			if(j==ps) ans[j][i]=a[j][L[j]],++L[j];
			else ans[j][i]=a[j][R[j]],--R[j];
	}
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=m;++j)
		printf("%d ",ans[i][j]);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}