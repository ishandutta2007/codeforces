#include<bits/stdc++.h>
using namespace std;
int n,x[1111],y[1111],a[1111],b[1111],X,Y;
map<pair<int,int>,int> mp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for (int i=1;i<=n;i++)
	{
		mp[make_pair(a[i],b[i])]=1;
	}
	for (int i=1;i<=n;i++)
	{
		X=x[1]+a[i];Y=y[1]+b[i];
		bool f=0;
		for (int j=2;j<=n;j++)
		{
			if (mp.find(make_pair(X-x[j],Y-y[j]))==mp.end())
			{
				f=1;
				break;
			}
		}
		if (!f)
		{
			printf("%d %d\n",X,Y);
			return 0;
		}
	}
	return 0;
}