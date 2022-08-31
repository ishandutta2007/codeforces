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
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;
const ll INF=1000000000000000000LL;

int n,m,k;
vector<pll> v[MaxN];
ll d[MaxN];
int ans;
int in[MaxN];

int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i)
		d[i]=INF;
	for (int i=1;i<=m;++i)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		v[x].push_back(pll(y,c));
		v[y].push_back(pll(x,c));
	}
	set<int> H;
	for (int i=1;i<=k;++i)
	{
		int x,c;
		scanf("%d%d",&x,&c);
		H.insert(x);
		if (d[x]<INF) ++ans;
		d[x]=min(d[x],(ll)c);
	}
	d[1]=0;
	priority_queue<pll> Q;
	Q.push(pll(0,1));
	for (auto x : H)
		Q.push(pll(-d[x],x));
	while (!Q.empty())
	{
		int x=Q.top().Y;
		ll dx=-Q.top().X;
		Q.pop();
		if (d[x]!=dx) continue;
		for (auto y : v[x])
			if (d[y.X]>d[x]+y.Y)
			{
				d[y.X]=d[x]+y.Y;
				Q.push(pll(-d[y.X],y.X));
			}
	}
	for (int i=1;i<=n;++i)
		for (auto x : v[i])
			if (d[i]+x.Y==d[x.X]) in[x.X]++;
	for (auto x : H)
		if (in[x]) ++ans;
	cout<<ans<<endl;
	return 0;
}