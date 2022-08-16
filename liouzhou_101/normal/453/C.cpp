#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;

int n,m;
vector<int> v[MaxN];
vector<int> p;
int x[MaxN];

int u[MaxN];

bool check()
{
	queue<int> Q;
	Q.push(p[0]);
	u[p[0]]=1;
	while (!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for (auto y : v[x])
			if (!u[y])
			{
				u[y]=1;
				Q.push(y);
			}
	}
	for (auto x : p)
		if (!u[x]) return 0;
	return 1;
}

vector<int> r;
int pre[MaxN];

void DFS(int x)
{
	u[x]=1;
	r.push_back(x);
	::x[x]^=1;
	for (auto y : v[x])
	{
		if (u[y]) continue;
		pre[y]=x;
		DFS(y);
		r.push_back(x);
		::x[x]^=1;
	}
	if (::x[x]&&pre[x])
	{
		r.push_back(pre[x]);
		::x[pre[x]]^=1;
		r.push_back(x);
		::x[x]^=1;
	}
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
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&x[i]);
		if (x[i]) p.push_back(i);
	}
	if (p.empty())
	{
		puts("0");
		puts("");
		return 0;
	}
	if (!check())
	{
		puts("-1");
		return 0;
	}
	memset(u,0,sizeof(u));
	DFS(p[0]);
	if (x[p[0]])
	{
		cout<<r.size()-1<<endl;
		for (int i=1;i<r.size();++i) printf("%d ",r[i]);
	}
	else
	{
		cout<<r.size()<<endl;
		for (int i=0;i<r.size();++i) printf("%d ",r[i]);
	}
	return 0;
}