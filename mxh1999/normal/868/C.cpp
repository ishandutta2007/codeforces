#include<bits/stdc++.h>
using namespace std;

int M[110];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	bool ans=false;
	for (int i=1;i<=n;i++)
	{
		int a=0;
		for (int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			a=a*2+x;
		}
		M[a]++;
	}
	if (M[0])	ans=true;
	for (int i=1;i<(1<<m);i++)
			for (int j=i+1;j<(1<<m);j++)
				if (M[i] && M[j] && ((i&j)==0))
					ans=true;
	if (ans)	printf("yes\n");else printf("no\n");
	return 0;
}