#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,d,m;
	scanf("%d%d",&n,&d);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int u=x+y;
		int v=y-x;
		if (v<=d && v>=-d && u>=d && u<=2*n-d)
			printf("YES\n");else printf("NO\n");
	}
	return 0;
}