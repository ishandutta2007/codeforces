#include <iostream>
#include <vector>
using namespace std;
bool p[1000005],ok[1000005];
vector<int> d[1000005];
int main()
{
	int n;
	cin >> n;
	for (int i=2;i<1000005;i++)
	{
		if (!p[i])
		{
			for (int x=2*i;x<1000005;x+=i)
			{
				p[x]=1;
				d[x].push_back(i);
			}
			d[i].push_back(i);
		}
	}
	for (int i=0;i<d[n].size();i++)
	{
		for (int x=d[n][i]+1;x<1000005;x++)
		{
			if ((x/d[n][i]+(x%d[n][i]!=0))*d[n][i]==n)
			ok[x]=1;
		}
	}
	int ans=(1<<30);
	for (int i=3;i<1000005;i++)
	{
		if (ok[i])
		{
			for (int x=0;x<d[i].size();x++)
			{
				if (i-d[i][x]+1>d[i][x])
				ans=min(ans,i-d[i][x]+1);
			}
		}
	}
	printf("%d",ans);
}