#include <bits/stdc++.h>
using namespace std;
int n,x[200005],s[200005],inv[200005];
pair<pair<int,int>,int> simulate(pair<pair<int,int>,int> p)
{
	if (p.second==1)
	{
		int st=inv[p.first.first],en=n;
		while (st!=en)
		{
			int mid=(st+en+1)/2;
			if (x[s[mid]]-x[p.first.first]<=p.first.second)
			st=mid;
			else
			en=mid-1;
		}
		return {{s[st],p.first.second-(x[s[st]]-x[p.first.first])},-p.second};
	}
	else
	{
		int st=1,en=inv[p.first.first];
		while (st!=en)
		{
			int mid=(st+en)/2;
			if (x[p.first.first]-x[s[mid]]<=p.first.second)
			en=mid;
			else
			st=mid+1;
		}
		return {{s[st],p.first.second-(x[p.first.first]-x[s[st]])},-p.second};
	}
}
bool cmp(int a,int b)
{
	return x[a]<x[b];
}
int main()
{
	int q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		s[i]=i;
	}
	sort(s+1,s+n+1,cmp);
	for (int i=1;i<=n;i++)
	inv[s[i]]=i;
	while (q--)
	{
		int a,l;
		scanf("%d%d",&a,&l);
		pair<pair<int,int>,int> p({a,l},1);
		while (1)
		{
			auto p2=simulate(p),p3=simulate(p2);
			if (p.first.first==p2.first.first && p2.first.first==p3.first.first)
			break;
			p=p3;
			if (p2.first.first!=p3.first.first)
			p.first.second%=2*(x[p2.first.first]-x[p3.first.first]);
			p=simulate(p);
		}
		printf("%d\n",p.first);
	}
}