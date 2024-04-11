#include <iostream>
using namespace std;
bool m[1005][1005];
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if ((a>1 && b>1) || ((n==2 || n==3) && max(a,b)==1))
	{
		printf("NO");
		return 0;
	}
	bool inv=0;
	if (a<b)
	{
		swap(a,b);
		inv=1;
	}
	if (a==b)
	{
		for (int i=2;i<=n;i++)
		{
			m[i-1][i]=1;
			m[i][i-1]=1;
		}
		goto out;
	}
	for (int i=a;i<=n;i++)
	{
		for (int x=a;x<i;x++)
		{
			m[i][x]=1;
			m[x][i]=1;
		}
	}
	out:
	printf("YES\n");
	for (int i=1;i<=n;i++)
	{
		for (int x=1;x<=n;x++)
		printf("%d",(m[i][x]^(inv && i!=x)));
		printf("\n");
	}
}