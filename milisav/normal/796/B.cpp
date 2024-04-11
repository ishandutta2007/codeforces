#include <bits\stdc++.h>
using namespace std;
int n,m,k;
bool h[1000005];
int u,v;
int x=1;
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&u);
		h[u]=true;
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&u,&v);
		if(!h[x])
		{
			if(u==x) x=v;
			else
			{
				if(x==v) x=u;
			}
		}
	}
	printf("%d",x);
	return 0;
}