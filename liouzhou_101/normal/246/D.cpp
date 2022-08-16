#include<cstdio>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int MaxN=100010;

int n,m;
vector<int> w[MaxN],v[MaxN];
set<int> H;
int c[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
		w[c[i]].push_back(i);
	}
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int most=-1,get=0;
	for (int i=1;i<=100000;++i)
	{
		if (w[i].empty()) continue;
		H.clear();
		for (vector<int>::iterator x=w[i].begin();x!=w[i].end();++x)
			for (vector<int>::iterator it=v[*x].begin();it!=v[*x].end();++it)
				if (c[*it]!=i) H.insert(c[*it]);
		if ((int)H.size()>most)
		{
			most=H.size();
			get=i;
		}
	}
	cout<<get<<endl;
	return 0;
}