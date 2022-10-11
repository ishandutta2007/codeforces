#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,pair<int,int> > > v;
int arr[200005],idx[105];
int main()
{
	int n,q,m;
	scanf("%d%d%d",&n,&q,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	while (q--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		v.push_back(make_pair(t,make_pair(l,r)));
	}
	for (int i=0;i<m;i++)
	scanf("%d",&idx[i]);
	for (int i=v.size()-1;i>=0;i--)
	{
		int t=v[i].first,l=v[i].second.first,r=v[i].second.second;
		for (int x=0;x<m;x++)
		{
			if (idx[x]>=l && idx[x]<=r)
			{
				if (t==1)
				{
					idx[x]--;
					if (idx[x]<l)
					idx[x]=r;
				}
				else
				idx[x]=r-idx[x]+l;
			}
		}
	}
	for (int i=0;i<m;i++)
	printf("%d ",arr[idx[i]]);
}