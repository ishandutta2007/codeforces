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
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

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

int n,m,s;

struct event
{
	int v,p;
	bool operator < (event A) const
	{
		return v<A.v;
	}
};

struct node
{
	int b,c,p;
	bool operator < (node A) const
	{
		return b<A.b;
	}
};

event a[MaxN];
node p[MaxN];

int ans[MaxN];

bool check(int k)
{
	priority_queue<pii> Q;
	ll need=0;
	for (int i=m,j=n;i>=1;i-=k)
	{
		while (j>=1&&p[j].b>=a[i].v)
		{
			Q.push(pii(-p[j].c,p[j].p));
			--j;
		}
		if (Q.empty()) return false;
		need-=Q.top().X;
		for (int x=0;x<k&&i-x>=1;++x)
			ans[a[i-x].p]=Q.top().Y;
		Q.pop();
	}
	return need<=s;
}

int main()
{
	cin>>n>>m>>s;
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&a[i].v);
		a[i].p=i;
	}
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].b);
		p[i].p=i;
	}
	for (int i=1;i<=n;++i)
		scanf("%d",&p[i].c);
	sort(a+1,a+m+1);
	sort(p+1,p+n+1);
	check(2);
	int L=0,R=n,ans=n+1;
	while (L<=R)
	{
		int m=(L+R)>>1;
		if (check(m))
		{
			ans=m;
			R=m-1;
		}
		else
			L=m+1;
	}
	if (ans<=n)
	{
		puts("YES");
		check(ans);
		for (int i=1;i<=m;++i)
			printf("%d ",::ans[i]);
	}
	else
		puts("NO");
	return 0;
}