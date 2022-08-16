#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=25;

int n;
int p[MaxN];

void init()
{
	int m;
	cin>>m;
	int u=0;
	while (m--)
	{
		int x;
		cin>>x;
		if (x==u)
			++p[n];
		else
		{
			p[++n]=1;
			u=x;
		}
	}
}

vector<pair<int,int> > v;

void solve_1(int k,int a,int b)
{
	if (k==n)
	{
		for (int i=1;i<=p[k];++i)
			v.push_back(make_pair(a,b));
		return;
	}
	int c=6-a-b;
	solve_1(k+1,a,c);
	for (int i=1;i<=p[k];++i)
		v.push_back(make_pair(a,b));
	solve_1(k+1,c,b);
}

void solve_0(int k,int a,int b)
{
	int c=6-a-b;
	if (k==n)
	{
		for (int i=1;i<p[k];++i)
			v.push_back(make_pair(a,c));
		v.push_back(make_pair(a,b));
		for (int i=1;i<p[k];++i)
			v.push_back(make_pair(c,b));
		return;
	}
	if (p[k]==1)
	{
		solve_1(k,a,b);
		return;
	}
	solve_1(k+1,a,b);
	for (int i=1;i<=p[k];++i)
		v.push_back(make_pair(a,c));
	solve_1(k+1,b,a);
	for (int i=1;i<=p[k];++i)
		v.push_back(make_pair(c,b));
	solve_0(k+1,a,b);
}

void work()
{
	solve_0(1,1,3);
	cout<<v.size()<<endl;
	for (int i=0;i<v.size();++i)
		printf("%d %d\n",v[i].first,v[i].second);
}

int main()
{
	init();
	work();
	return 0;
}