#include<bits/stdc++.h>
using namespace std;

const int mo=1e9+7;
const int maxn=1010;
char s[maxn];
int a[maxn];
int ans[maxn],anss;
int n,m;

int f[maxn][maxn][2];
void getans()
{
	f[0][0][1]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++)
		{
			f[i][j][0]=(f[i][j][0]+f[i-1][j][0])%mo;
			f[i][j+1][0]=(f[i][j+1][0]+f[i-1][j][0])%mo;
			if (a[i]==1)
			{
				f[i][j][0]=(f[i][j][0]+f[i-1][j][1])%mo;
				f[i][j+1][1]=(f[i][j+1][1]+f[i-1][j][1])%mo;
			}	else
			{
				f[i][j][1]=(f[i][j][1]+f[i-1][j][1])%mo;
			}
		}
	for (int i=1;i<=n;i++)
		ans[i]=(f[n][i][0]+f[n][i][1])%mo;
}
int ok(int x)
{
	int num=0;
	while (x!=1 && num<=m)
	{
		num++;
		x=__builtin_popcount(x);
	}
	return num;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	scanf("%d",&m);
	if (m==0)
	{
		printf("%d\n",1);
		return 0;
	}
	getans();
	for (int i=1;i<=n;i++)
	if (ok(i)==m-1)
	{
		anss=(anss+ans[i])%mo;
	}
	if (m==1)	printf("%d\n",(anss-1+mo)%mo);else printf("%d\n",anss);
	return 0;
}