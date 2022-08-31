#include<cstdio>
#include<iostream>

using namespace std;

int p[10][10][10];

int main()
{
	int n,up;
	for (int i=1;i<=6;++i)
		for (int j=1;j<=6;++j)
			if (i!=j&&i+j!=7)
				for (int k=1;k<=6;++k)
					if (k!=i&&k!=j&&k!=7-i&&k!=7-j)
						p[i][j][k]=1;
	cin>>n>>up;
	int a,b;
	cin>>a>>b;
	up=7-up;
	for (int i=1;i<=n;++i)
	{
		cin>>a>>b;
		if (!p[a][b][up])
		{
			puts("NO");
			return 0;
		}
		up=7-up;
	}
	puts("YES");
	return 0;
}