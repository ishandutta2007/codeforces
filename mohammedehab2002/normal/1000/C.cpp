#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<long long,int> > v;
long long cnt[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		long long a,b;
		scanf("%I64d%I64d",&a,&b);
		v.push_back({a,1});
		v.push_back({b+1,-1});
	}
	sort(v.begin(),v.end());
	int bal=0;
	for (int i=0;i<v.size();i++)
	{
		bal+=v[i].second;
		if (i+1!=v.size())
		cnt[bal]+=v[i+1].first-v[i].first;
	}
	for (int i=1;i<=n;i++)
	printf("%I64d ",cnt[i]);
}