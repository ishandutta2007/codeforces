#include <iostream>
#include <vector>
using namespace std;
int arr[105];
vector<pair<int,int> > v;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	bool b=0;
	for (int i=0;i<n;i++)
	{
		if (!i)
		{
			v.push_back(make_pair(0,0));
			if (arr[i]==0)
			b=1;
			continue;
		}
		if (arr[i]==0)
		v[v.size()-1].second++;
		else if (b)
		{
			v[v.size()-1].second++;
			b=0;
		}
		else
		v.push_back(make_pair(i,i));
	}
	if (b)
	printf("NO");
	else
	{
		printf("YES\n%d\n",v.size());
		for (int i=0;i<v.size();i++)
		printf("%d %d\n",v[i].first+1,v[i].second+1);
	}
}