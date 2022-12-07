#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=20010;
const int MAXM=12;
const int MAXK=200010;
int n,m,k,a[MAXN][MAXM],sd[MAXN],in1,in2,rc[MAXK],ans[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&in1,&in2);
		sd[in1]++;
		rc[in2]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]) ans[i]+=rc[j];
	for(int i=1;i<n;i++)
		printf("%d ",ans[i]-sd[i]);
	printf("%d\n",ans[n]-sd[n]);
	return 0;
}