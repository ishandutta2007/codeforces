#include<bits\stdc++.h>
using namespace std;
set<int> s[111111];
int n,m,b[111111],x,y;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		s[x].insert(y);
		s[y].insert(x);  
	}
	for (int i=1;i<=200;i++)
	{
		for (int j=1;j<=n;j++) b[j]=j;
		random_shuffle(b+1,b+n+1);
		b[n+1]=b[1];
		bool f=0;
		for (int j=1;j<=m;j++)
		{
			if (s[b[j]].find(b[j+1])!=s[b[j]].end()) f=1;
		}
		if (!f)
		{
			for (int j=1;j<=m;j++)
			{
				printf("%d %d\n",b[j],b[j+1]);
			}
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}