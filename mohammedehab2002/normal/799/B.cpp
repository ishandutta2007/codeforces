#include <iostream>
#include <set>
using namespace std;
set<pair<int,int> > s[3];
int arr[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<2;i++)
	{
		for (int x=0;x<n;x++)
		{
			int a;
			scanf("%d",&a);
			s[a-1].insert(make_pair(arr[x],x));
		}
	}
	int m;
	scanf("%d",&m);
	while (m--)
	{
		int a;
		scanf("%d",&a);
		if (!s[a-1].size())
		{
			printf("-1 ");
			continue;
		}
		pair<int,int> p=*(s[a-1].begin());
		for (int i=0;i<3;i++)
		{
			if (s[i].find(p)!=s[i].end())
			s[i].erase(s[i].find(p));
		}
		printf("%d ",p.first);
	}
}