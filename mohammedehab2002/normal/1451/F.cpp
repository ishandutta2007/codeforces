#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
		}
		bool sec=1;
		for (int s=0;s<n+m-1;s++)
		{
			int x=0;
			for (int i=0;i<min(n,s+1);i++)
			{
				if (s-i<m)
				x^=a[i][s-i];
			}
			sec&=(!x);
		}
		puts(sec? "Jeel":"Ashish");
	}
}