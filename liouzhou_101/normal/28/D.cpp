#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int MaxN=300010;
const int INF=2000000000;

int n;
int v[MaxN],c[MaxN],L[MaxN],R[MaxN];
vector<int> w[MaxN];

void init()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		scanf("%d%d%d%d",&v[i],&c[i],&L[i],&R[i]);
		w[c[i]+L[i]+R[i]].push_back(i);
	}
}

map<int,pair<int,vector<int> > > F;

int ans;
vector<int> list;

void solve(vector<int> w)
{
	F.clear();
	F[c[w[0]]+L[w[0]]+R[w[0]]].first=0;
	int n=w.size();
	for (int i=0;i<n;++i)
	{
		map<int,pair<int,vector<int> > >::iterator it=F.find(R[w[i]]+c[w[i]]),x=F.find(R[w[i]]);
		if (it==F.end()) continue;
		if (x==F.end())
		{
			F[R[w[i]]].first=-INF;
			x=F.find(R[w[i]]);
		}
		if (x->second.first<it->second.first+v[w[i]])
		{
			x->second.first=it->second.first+v[w[i]];
			x->second.second.push_back(w[i]);
		}
	}
	map<int,pair<int,vector<int> > >::iterator it=F.find(0);
	if (it==F.end()) return;
	if (it->second.first>ans)
	{
		ans=it->second.first;
		list.clear();
		int now=MaxN;
		for (int i=0;!F[i].second.empty();)
		{
			now=F[i].second[lower_bound(F[i].second.begin(),F[i].second.end(),now)-F[i].second.begin()-1];
			list.push_back(now);
			i+=c[now];
		}
	}
}

void work()
{
	for (int i=1;i<MaxN;++i)
		if (!w[i].empty())
			solve(w[i]);
	cout<<list.size()<<endl;
	int flag=0;
	for (vector<int>::reverse_iterator it=list.rbegin();it!=list.rend();++it)
	{
		if (flag) putchar(' ');
		printf("%d",*it+1);
		flag=1;
	}
	puts("");
}

int main()
{
	init();
	work();
	return 0;
}