#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

const int MaxN=100010;

int n;
char s[MaxN][30];
int pre[MaxN],val[MaxN];
vector<string> p;
vector<int> v[MaxN];

int m;
vector<pair<int,int> > w[MaxN];
int ans[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%s%d",s[i],&pre[i]);
		v[pre[i]].push_back(i);
		p.push_back(s[i]);
	}
	sort(p.begin(),p.end());
	for (int i=1;i<=n;++i)
		val[i]=lower_bound(p.begin(),p.end(),s[i])-p.begin();
	cin>>m;
	for (int i=1;i<=m;++i)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		w[x].push_back(make_pair(k,i));
	}
}

map<int,set<int> > H[MaxN];
int at[MaxN],dis[MaxN],size[MaxN];

void build(int x)
{
	size[x]=1;
	at[x]=x;
	int get=x;
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
	{
		dis[*it]=dis[x]+1;
		build(*it);
		size[x]+=size[*it];
		if (get==x||size[*it]>size[get]) get=*it;
	}
	at[x]=at[get];
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=get)
		{
			for (map<int,set<int> >::iterator p=H[at[*it]].begin();p!=H[at[*it]].end();++p)
				for (set<int>::iterator q=p->second.begin();q!=p->second.end();++q)
					H[at[x]][p->first].insert(*q);
		}
	H[at[x]][dis[x]].insert(val[x]);
	for (vector<pair<int,int> >::iterator it=w[x].begin();it!=w[x].end();++it)
		ans[it->second]=H[at[x]][dis[x]+it->first].size();
}

void work()
{
	build(0);
	for (int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
}

int main()
{
	init();
	work();
	return 0;
}