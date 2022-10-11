#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> s;
vector<pair<int,int> > c;
int main()
{
	int n;
	scanf("%d",&n);
	int l;
	scanf("%d",&l);
	for (int i=1;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a==l)
		{
			printf("NO");
			return 0;
		}
		else if (abs(a-l)>1)
		s.insert(abs(a-l));
		else
		c.push_back({l,a});
		l=a;
	}
	if (s.size()>1)
	{
		printf("NO");
		return 0;
	}
	int ans;
	if (s.empty())
	ans=1;
	else
	ans=(*s.begin());
	for (pair<int,int> i:c)
	{
		if ((i.first-1)/ans!=(i.second-1)/ans && ans!=1)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	printf("1000000000 %d",ans);
}