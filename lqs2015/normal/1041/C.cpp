#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n,m,d,ans[222222],cnt,k;
set<pair<int,int> > s;
pair<int,int> a[222222];
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (s.empty())
		{
			ans[a[i].second]=++cnt;
			s.insert(make_pair(a[i].first,ans[a[i].second]));
			continue; 
		}
		k=s.begin()->first;
		if (a[i].first-k>d) 
		{
			ans[a[i].second]=s.begin()->second;
			s.erase(s.begin());
			s.insert(make_pair(a[i].first,ans[a[i].second]));  
		}
		else
		{
			ans[a[i].second]=++cnt;
			s.insert(make_pair(a[i].first,ans[a[i].second])); 
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}