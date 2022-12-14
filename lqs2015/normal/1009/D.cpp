#include<iostream>
#include<cstdio>
using namespace std;
pair<int,int> ans[111111];
int n,m,cnt;
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d%d",&n,&m);
	if (m<n-1)
	{
		printf("Impossible\n");
		return 0;
	}
	for (int i=1;i<n;i++) ans[++cnt]=make_pair(i,i+1);
	for (int i=2;i<=n;i++)
	{
		if (cnt==m) break;
		for (int j=1;j<i-1;j++)
		{
			if (gcd(i,j)==1) ans[++cnt]=make_pair(j,i);
			if (cnt==m) break;
		}
	}
	if (cnt==m) 
	{
		printf("Possible\n");
		for (int i=1;i<=m;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}
	else printf("Impossible\n");
	return 0;
}