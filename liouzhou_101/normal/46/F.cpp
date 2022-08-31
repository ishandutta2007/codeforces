#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>

using namespace std;

const int MaxN=1010;

int n,m,k;
vector<pair<int,int> > v[MaxN];

struct event
{
	vector<string> p;
	string s[MaxN];
	int room[MaxN];
	int F[MaxN];
	bitset<MaxN> key[MaxN],people[MaxN];
	bitset<MaxN> door;
	void init()
	{
		for (int i=1;i<=k;++i)
		{
			int T;
			cin>>s[i]>>room[i]>>T;
			p.push_back(s[i]);
			while (T--)
			{
				int x;
				cin>>x;
				key[room[i]][x]=1;
			}
		}
		sort(p.begin(),p.end());
		for (int i=1;i<=k;++i)
			people[room[i]][lower_bound(p.begin(),p.end(),s[i])-p.begin()+1]=1;
	}
	int father(int x)
	{
		return (F[x]==x)?x:F[x]=father(F[x]);
	}
	void deal()
	{
		for (int i=1;i<=n;++i)
			F[i]=i;
		while (1)
		{
			int flag=0;
			for (int i=1;i<=n;++i)
			{
				int x=father(i);
				for (vector<pair<int,int> >::iterator it=v[i].begin();it!=v[i].end();++it)
					if (!door[it->second]&&key[x][it->second])
					{
						flag=1;
						door[it->second]=1;
						int y=father(it->first);
						F[y]=x;
						key[x]|=key[y];
						people[x]|=people[y];
					}
			}
			if (!flag) break;
		}
	}
}Day1,Day2;

void init()
{
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(make_pair(y,i));
		v[y].push_back(make_pair(x,i));
	}
	Day1.init();
	Day2.init();
}

void work()
{
	Day1.deal();
	Day2.deal();
	if (Day1.door!=Day2.door)
	{
		puts("NO");
		return;
	}
	for (int i=1;i<=n;++i)
	{
		int x=Day1.father(i),y=Day2.father(i);
		if (Day1.key[x]!=Day2.key[y]||Day1.people[x]!=Day2.people[y])
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main()
{
	init();
	work();
	return 0;
}