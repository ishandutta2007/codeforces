#include <bits/stdc++.h>
using namespace std;
int mn[200005];
vector<pair<int,int> > v;
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v.push_back({a,b});
	}
	int st=1,en=q+1;
	while (st!=en)
	{
		int mid=(st+en)/2;
		for (int i=0;i<=n;i++)
		mn[i]=m;
		for (int i=0;i<mid;i++)
		{
			if (v[i].first%2)
			mn[v[i].first/2+1]=min(mn[v[i].first/2+1],v[i].second/2);
		}
		for (int i=1;i<=n;i++)
		mn[i]=min(mn[i],mn[i-1]);
		bool yes=1;
		for (int i=0;i<mid;i++)
		{
			if (v[i].first%2==0)
			yes&=(mn[v[i].first/2]>=v[i].second/2);
		}
		if (yes)
		st=mid+1;
		else
		en=mid;
	}
	for (int i=1;i<st;i++)
	puts("YES");
	for (int i=st;i<=q;i++)
	puts("NO");
}