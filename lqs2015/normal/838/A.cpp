#include<iostream>
#include<cstdio> 
#include<string>
using namespace std;
int a[2555][2555],sum0[2555][2555],n,m,mn,cur,z;
char s[2555][2555];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			a[i][j]=s[i][j-1]-'0';
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			sum0[i][j]=sum0[i-1][j]+sum0[i][j-1]-sum0[i-1][j-1]+(a[i][j]==0);
		}
	}
	mn=1e9;
	for (int k=2;k<=max(n,m);k++)
	{
		cur=0;
		for (int i=1;i<=(n+k-1)/k;i++)
		{
			for (int j=1;j<=(m+k-1)/k;j++)
			{
				z=0;
				if (i*k>n)
				{
				    z+=(i*k-n)*k;
				    if (j*k>m) 
					{
						z=z+(j*k-m)*(k)-(j*k-m)*(i*k-n);
					}
				} 
				else if (j*k>m)
				{
					z+=(j*k-m)*k;
				}
				z=z+sum0[min(n,i*k)][min(m,j*k)]-sum0[min(n,i*k)][(j-1)*k]-sum0[(i-1)*k][min(m,j*k)]+sum0[(i-1)*k][(j-1)*k];
				cur+=min(z,k*k-z);
			}
		}
		mn=min(mn,cur);
	}
	printf("%d\n",mn);
	return 0;
}