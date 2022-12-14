#include<bits/stdc++.h>
using namespace std;
int n,m,a[1111][1111],r[1111][1111],c[1111][1111],ct,R[1111],C[1111],ans;
pair<int,int> b[1111];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) b[j]=make_pair(a[i][j],j);
		sort(b+1,b+m+1);
		ct=0;
		for (int j=1;j<=m;j++)
		{
			if (b[j].first==b[j-1].first) r[i][b[j].second]=ct;
			else r[i][b[j].second]=++ct;
 		}
 		R[i]=ct;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++) b[j]=make_pair(a[j][i],j);
		sort(b+1,b+n+1);
		ct=0;
		for (int j=1;j<=n;j++)
		{
			if (b[j].first==b[j-1].first) c[b[j].second][i]=ct;
			else c[b[j].second][i]=++ct;
 		}
 		C[i]=ct;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (r[i][j]>c[i][j]) ans=max(R[i],C[j]-c[i][j]+r[i][j]);
			else ans=max(C[j],R[i]-r[i][j]+c[i][j]);
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}