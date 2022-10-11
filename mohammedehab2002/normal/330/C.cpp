#include <iostream>
using namespace std;
pair<int,int> r[105],c[105];
bool ro=1,co=1;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		getchar();
		for (int x=0;x<n;x++)
		{
			char cur=getchar();
			if (cur=='.')
			{
				r[i]=make_pair(i+1,x+1);
				c[x]=make_pair(i+1,x+1);
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		if (!r[i].first)
		ro=0;
	}
	for (int i=0;i<n;i++)
	{
		if (!c[i].first)
		co=0;
	}
	if (ro)
	{
		for (int i=0;i<n;i++)
		printf("%d %d\n",r[i].first,r[i].second);
	}
	else if (co)
	{
		for (int i=0;i<n;i++)
		printf("%d %d\n",c[i].first,c[i].second);
	}
	else
	printf("-1");
}