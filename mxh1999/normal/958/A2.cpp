#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mo=998244353;
char a[2010][210],b[210][2010];
ll A[2010],B[210];
int nxt[210];
int n,m;

int kmp()
{
	int j=0;
	nxt[1]=0;
	for (int i=2;i<=m;i++)
	{
		while (j && B[j+1]!=B[i])	j=nxt[j];
		if (B[j+1]==B[i])	j++;
		nxt[i]=j;
	}
	j=0;
	for (int i=1;i<=n;i++)
	{
		while (j && B[j+1]!=A[i])	j=nxt[j];
		if (B[j+1]==A[i])	j++;
		if (j==m)	return i-m+1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for (int j=1;j<=m;j++)
		scanf("%s",b[j]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			A[i]=(A[i]*27+a[i][j]-'a'+1)%mo;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			B[i]=(B[i]*27+b[i][j]-'a'+1)%mo;
	ll base=1;
	for (int i=1;i<m;i++)
		base=(base*27)%mo;
	for (int i=1;i<=n-m+1;i++)
	{
		int q=kmp();
		if (q)
		{
			printf("%d %d\n",q,i);
			return 0;
		}
		if (i!=n-m+1)
		{
			for (int j=1;j<=m;j++)
				B[j]=(((B[j]-(base*(b[j][i]-'a'+1))%mo+mo)%mo)*27+b[j][i+m]-'a'+1)%mo;
		}
	}
	return 0;
}