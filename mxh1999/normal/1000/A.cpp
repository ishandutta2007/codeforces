#include<bits/stdc++.h>
using namespace std;

char a[110][10],b[110][10];
int cnt1[10][5],cnt2[10][5];
int n;
bool cmp(char *a,char *b)
{
	return strlen(a)<strlen(b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		int t=strlen(a[i]);
		int q;
		if (a[i][t-1]=='S')	q=1;else
		if (a[i][t-1]=='L')	q=2;else
			q=3;
		cnt1[t][q]++;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		int t=strlen(a[i]);
		int q;
		if (a[i][t-1]=='S')	q=1;else
		if (a[i][t-1]=='L')	q=2;else
			q=3;
		cnt2[t][q]++;
	}
	int ans=0;
	for (int i=1;i<=6;i++)
		for (int j=1;j<=3;j++)
			ans+=cnt1[i][j]-min(cnt1[i][j],cnt2[i][j]);
	printf("%d\n",ans);
	return 0;
}