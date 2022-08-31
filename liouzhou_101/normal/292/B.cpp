#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;

int n,m;
vector<int> v[MaxN];
int u[MaxN];

void BFS(int x)
{
	queue<int> Q;
	Q.push(x);
	u[x]=1;
	while (!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (!u[*it])
			{
				u[*it]=u[x]+1;
				Q.push(*it);
			}
	}
}

bool bus()
{
	for (int i=1;i<=n;++i)
		if (v[i].size()==1)
		{
			BFS(i);
			int x=0;
			for (int j=1;j<=n;++j)
				x=max(x,u[j]);
			return x==n;
		}
	return false;
}

bool ring()
{
	for (int i=1;i<=n;++i)
		if (v[i].size()!=2) return false;
	BFS(1);
	for (int i=1;i<=n;++i)
		if (!u[i]) return false;
	return true;
}

bool star()
{
	pii p=pii(0,0);
	for (int i=1;i<=n;++i)
	{
		p=max(p,pii(v[i].size(),i));
	}
	if (p.X!=n-1) return false;
	for (int i=1;i<=n;++i)
		if (i!=p.Y) if (v[i].size()!=1) return false;
	return true;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (bus())
		puts("bus topology");
	else if (ring())
		puts("ring topology");
	else if (star())
		puts("star topology");
	else
		puts("unknown topology");
	return 0;
}