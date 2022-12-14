#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
long long n,m,x[222222],y[222222],l[222222],r[222222],ans[222222],pre,cur,ks,id;
pair<long long,long long> k[222222];
pair<pair<long long,long long>,long long> brid[222222];
multiset<pair<long long,long long> > s;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&x[i],&y[i]);
		if (i>=2) 
		{
			l[i-1]=x[i]-y[i-1];
			r[i-1]=y[i]-x[i-1];
		}
	}
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d",&k[i].first);
		k[i].second=i;
	}
	sort(k+1,k+m+1);
	for (long long i=1;i<n;i++)
	{
		if (l[i]>k[m].first || r[i]<k[1].first)
		{
			printf("No\n");
			return 0;
		}
		l[i]=lower_bound(k+1,k+m+1,make_pair(l[i],0ll))-k;
		pre=r[i];
		r[i]=lower_bound(k+1,k+m+1,make_pair(r[i]+1,0ll))-k;
		if (r[i]>m || k[r[i]].first>pre) r[i]--;
		brid[i]=make_pair(make_pair(l[i],r[i]),i);
	}
	sort(brid+1,brid+n);
	cur=1;
	for (long long i=1;i<=m;i++)
	{
		while(cur<n && brid[cur].first.first<=i) 
		{
			s.insert(make_pair(brid[cur].first.second,brid[cur].second));
			cur++;
		}
		if (s.empty()) continue;
		ks=s.begin()->first;id=s.begin()->second;
		if (ks<i)
		{
			printf("No\n");
			return 0;
		}
		ans[id]=k[i].second;
		s.erase(s.begin());
	}
	printf("Yes\n");
	for (long long i=1;i<n;i++)
	{
		printf("%I64d ",ans[i]);
	}
	return 0;
}