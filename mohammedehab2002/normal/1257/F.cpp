#include <bits/stdc++.h>
using namespace std;
#define pw (1<<15)-1
map<vector<int>,int> m;
int a[105];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<=pw;i++)
	{
		vector<int> v;
		for (int j=0;j<n;j++)
		v.push_back(__builtin_popcount((a[j]&pw)^i));
		for (int j=0;j<n;j++)
		v[j]-=v.back();
		m[v]=i;
	}
	for (int i=0;i<n;i++)
	a[i]>>=15;
	for (int i=0;i<=pw;i++)
	{
		vector<int> v;
		for (int j=0;j<n;j++)
		v.push_back(-__builtin_popcount(a[j]^i));
		for (int j=0;j<n;j++)
		v[j]-=v.back();
		if (m.count(v))
		{
			printf("%d",(m[v]|(i<<15)));
			return 0;
		}
	}
	printf("-1");
}