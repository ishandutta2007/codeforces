#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=110;

int n;
int d[MaxN];

struct node
{
	int x,p,u;
};

vector<node> v[MaxN];

int F[MaxN];

int father(int x)
{
	return (F[x]==x)?x:F[x]=father(F[x]);
}

void init()
{
	cin>>n;
	for (int i=0;i<=6;++i)
		F[i]=i;
	for (int i=1;i<=n;++i)
	{
		int x,y;
		cin>>x>>y;
		d[x]^=1;
		d[y]^=1;
		v[x].push_back((node){y,i,0});
		v[y].push_back((node){x,i,1});
		F[father(x)]=father(y);
	}
}

vector<node> way;
int used[MaxN];

void travel(int x)
{
	for (vector<node>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (!used[it->p])
		{
			used[it->p]=1;
			travel(it->x);
			way.push_back(*it);
		}
}

void work()
{
	set<int> H;
	for (int i=0;i<=6;++i)
		for (vector<node>::iterator it=v[i].begin();it!=v[i].end();++it)
			H.insert(father(it->x));
	if (H.size()>1)
	{
		puts("No solution");
		return;
	}
	vector<int> p;
	for (int i=0;i<=6;++i)
		if (d[i]) p.push_back(i);
	if (p.size()>2)
	{
		puts("No solution");
		return;
	}
	if (p.empty())
		p.push_back(*H.begin());
	travel(p[0]);
	for (int i=n-1;i>=0;--i)
	{
		printf("%d ",way[i].p);
		puts((way[i].u)?"-":"+");
	}
}

int main()
{
	init();
	work();
	return 0;
}