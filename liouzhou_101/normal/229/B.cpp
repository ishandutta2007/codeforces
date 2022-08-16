#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;

const int MaxN=100010;
const int INF=2000000000;

int n,m;
vector<pair<int,int> > v[MaxN];
map<int,int> w[MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		v[x].push_back(make_pair(y,c));
		v[y].push_back(make_pair(x,c));
	}
	for (int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		while (k--)
		{
			int x;
			scanf("%d",&x);
			w[i][x]=x+1;
		}
		int last=INF;
		int need=INF;
		for (map<int,int>::reverse_iterator x=w[i].rbegin();x!=w[i].rend();++x)
		{
			if (x->first+1==last)
			{
				x->second=need;
				last=x->first;
			}
			else
			{
				x->second=x->first+1;
				last=x->first;
				need=x->second;
			}
		}
	}
}

int dis[MaxN];
priority_queue<pair<int,int> > H;

void work()
{
	for (int i=1;i<=n;++i)
		dis[i]=INF;
	H.push(make_pair(dis[1]=0,1));
	while (!H.empty())
	{
		pair<int,int> p=H.top();
		H.pop();
		int nowx=p.second;
		int nowd=-p.first;
		if (dis[nowx]!=nowd) continue;
		int get=w[nowx][nowd];
		if (get) nowd=get;
		for (vector<pair<int,int> >::iterator it=v[nowx].begin();it!=v[nowx].end();++it)
			if (dis[it->first]>nowd+it->second)
				H.push(make_pair(-(dis[it->first]=nowd+it->second),it->first));
	}
	if (dis[n]==INF)
		puts("-1");
	else
		cout<<dis[n]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}