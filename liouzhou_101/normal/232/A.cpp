#include<cstdio>
#include<iostream>

using namespace std;

int k;
int F[110];
int v[110][110];

int main()
{
	cin>>k;
	for (int i=3;i<=100;++i)
		F[i]=i*(i-1)*(i-2)/6;
	for (int i=100;i>=3;--i)
	{
		if (F[i]<=k)
		{
			int p=i;
			for (int x=1;x<=i;++x)
				for (int y=1;y<=i;++y)
					if (x!=y) v[x][y]=1;
			k-=F[i];
			while (k>0)
			{
				for (int x=i;x>=2;--x)
					if (x*(x-1)/2<=k)
					{
						k-=x*(x-1)/2;
						++p;
						for (int y=1;y<=x;++y)
							v[p][y]=v[y][p]=1;
						break;
					}
			}
			cout<<p<<endl;
			for (int i=1;i<=p;++i)
			{
				for (int j=1;j<=p;++j)
					printf("%d",v[i][j]);
				puts("");
			}
			break;
		}
	}
	return 0;
}