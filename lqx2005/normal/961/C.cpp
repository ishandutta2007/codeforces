#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
struct mat
{
	int a[maxn+5][maxn+5];
}b[4];
int n,id[maxn+5],p[maxn*2+5][maxn*2+5];
char s[maxn+5];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=3;i++) 
	{
		for(int j=1;j<=n;j++) 
		{
			scanf("%s",s+1);
			for(int k=1;k<=n;k++)
			{
				b[i].a[j][k]=s[k]-'0';
			}			
		}
	}
	int ans=4*n*n;
	for(int i=0;i<=3;i++) id[i]=i;
	do
	{
		for(int i=0;i<=3;i++)
		{
			int xn=id[i]/2;
			int yn=id[i]%2;
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					p[xn*n+j][yn*n+k]=b[i].a[j][k];
				}
			}

		}			
		int sum=0;
		for(int i=1;i<=2*n;i++)
		{
			for(int j=1;j<=2*n;j++)
			{
				if((i+j)%2==p[i][j]) sum++;
			}
		}
		ans=min(ans,sum);
		sum=0;
		for(int i=1;i<=2*n;i++)
		{
			for(int j=1;j<=2*n;j++)
			{
				if((i+j)%2!=p[i][j]) sum++;
			}
		}
		ans=min(ans,sum);
	}
	while(next_permutation(id,id+4));
	printf("%d\n",ans);
	return 0;
}