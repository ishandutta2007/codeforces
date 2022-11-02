#include<bits/stdc++.h>
using namespace std;
int t,n,m;char c[105][105];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&m);int res=0;
		for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
		for(int i=1;i<=n;i++) if(c[i][m]=='R') res++;
		for(int i=1;i<=m;i++) if(c[n][i]=='D') res++;
		printf("%d\n",res);
	}
	return 0;
}