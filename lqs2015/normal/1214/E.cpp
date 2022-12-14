#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[222222],c[222222],all;
pair<int,int> b[222222];
vector<int> p[222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=make_pair(a[i],i);
	}
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	c[1]=2*b[1].second-1;all=n;
	if (b[1].first==n) 
	{
		all++;c[all]=2*b[1].second;
	}
	else p[b[1].first].push_back(2*b[1].second);
	for (int i=2;i<=n;i++)
	{
		pair<int,int> cur=b[i];
		c[i]=2*cur.second-1;
		if (i+cur.first==all+1)
		{
			all++;c[all]=2*cur.second;
		}
		else
		{
			p[i+cur.first-1].push_back(2*cur.second);
		}
	}
	for (int i=1;i<=all;i++)
	{
		if (i!=all)
		{
			printf("%d %d\n",c[i],c[i+1]);
		}
		for (int j=0;j<p[i].size();j++)
		{
			printf("%d %d\n",c[i],p[i][j]);
		}
	}
	return Accepted;
}