#include <bits/stdc++.h>
using namespace std;
vector<int> v({0});
long long ans[1005];
long long query(vector<int> q)
{
	if (q.empty())
	return 0;
	printf("? %d",q.size());
	for (int i:q)
	printf(" %d",i);
	printf("\n");
	fflush(stdout);
	long long ret;
	scanf("%I64d",&ret);
	return ret;
}
int main()
{
	for (int i=0;i<(1<<13);i++)
	{
		if (__builtin_popcount(i)==6)
		v.push_back(i);
	}
	int n;
	scanf("%d",&n);
	for (int i=0;i<13;i++)
	{
		vector<int> q;
		for (int j=1;j<=n;j++)
		{
			if (v[j]&(1<<i))
			q.push_back(j);
		}
		long long ret=query(q);
		for (int j=1;j<=n;j++)
		{
			if (!(v[j]&(1<<i)))
			ans[j]|=ret;
		}
	}
	printf("!");
	for (int i=1;i<=n;i++)
	printf(" %I64d",ans[i]);
	printf("\n");
	fflush(stdout);
}