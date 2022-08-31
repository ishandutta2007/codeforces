#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=10010;

int m;
vector<pair<int,int> > v[MaxN];

void init()
{
	cin>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(y,i));
		v[y].push_back(make_pair(x,i));
	}
}

vector<int> odd;

int have;
int belong[MaxN];

void draw(int x)
{
	belong[x]=have;
	for (int i=0;i<v[x].size();++i)
		if (!belong[v[x][i].first])
			draw(v[x][i].first);
}

vector<int> way,p1,p2;
int used[MaxN];

void solve(int x)
{
	for (int i=0;i<v[x].size();++i)
		if (!used[v[x][i].second])
		{
			used[v[x][i].second]=1;
			solve(v[x][i].first);
			way.push_back(v[x][i].second);
		}
}

void work()
{
	for (int i=1;i<MaxN;++i)
		if (v[i].size()&1)
			odd.push_back(i);
	if (m<2||odd.size()>4)
	{
		puts("-1");
		return;
	}
	for (int i=1;i<MaxN;++i)
		if (!v[i].empty()&&!belong[i])
		{
			++have;
			draw(i);
		}
	if (have>2)
	{
		puts("-1");
		return;
	}
	if (have==1)
	{
		if (odd.size()==4)
		{
			v[odd[2]].push_back(make_pair(odd[3],m+1));
			v[odd[3]].push_back(make_pair(odd[2],m+1));
		}
		if (odd.empty())
		{
			for (int i=1;i<MaxN;++i)
				if (!v[i].empty())
				{
					solve(i);
					break;
				}
		}
		else
			solve(odd[0]);
		if (odd.size()==4)
		{
			for (int i=way.size()-1;i>=0;--i)
			{
				if (way[i]==m+1)
				{
					for (--i;i>=0;--i)
						p2.push_back(way[i]);
					break;
				}
				p1.push_back(way[i]);
			}
		}
		else
		{
			for (int i=way.size()-1;i>=1;--i)
				p1.push_back(way[i]);
			p2.push_back(way[0]);
		}
	}
	else
	{
		if (odd.size()==4)
			if (belong[odd[0]]==belong[odd[1]]&&belong[odd[1]]==belong[odd[2]]&&belong[odd[2]]==belong[odd[3]])
			{
				puts("-1");
				return;
			}
		int get=0;
		for (int i=0;i<odd.size();++i)
			if (belong[odd[i]]==1)
			{
				get=odd[i];
				break;
			}
		if (!get)
			for (int i=1;i<MaxN;++i)
				if (belong[i]==1)
				{
					get=i;
					break;
				}
		solve(get);
		for (int i=way.size()-1;i>=0;--i)
			p1.push_back(way[i]);
		way.clear();
		get=0;
		for (int i=0;i<odd.size();++i)
			if (belong[odd[i]]==2)
			{
				get=odd[i];
				break;
			}
		if (!get)
			for (int i=1;i<MaxN;++i)
				if (belong[i]==2)
				{
					get=i;
					break;
				}
		solve(get);
		for (int i=way.size()-1;i>=0;--i)
			p2.push_back(way[i]);
	}
	cout<<p1.size()<<endl;
	for (int i=0;i<p1.size();++i)
		printf("%d ",p1[i]);
	cout<<endl<<p2.size()<<endl;
	for (int i=0;i<p2.size();++i)
		printf("%d ",p2[i]);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	work();
	return 0;
}