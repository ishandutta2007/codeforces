#include <bits\stdc++.h>
using namespace std;
int a[200000];
int q;
int n;
int b[100001][501];
int p,k;
int s;
int c=500;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n && i<=c;i++)
	{
		for(int j=n;j>0;j--)
		{
			if(j+a[j]+i>n) b[j][i]=1;
			else b[j][i]=1+b[j+a[j]+i][i];
		}
	}
	scanf("%d",&q);
	while(q>0)
	{
		q--;
		scanf("%d %d",&p,&k);
		if(k>c)
		{
			s=0;
			while(p<=n)
			{
				p=p+a[p]+k;
				s++;
			}
			printf("%d\n",s);
		}
		else
		{
			printf("%d\n",b[p][k]);
		}
	}
	return 0;
}