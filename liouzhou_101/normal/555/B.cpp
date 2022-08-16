#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=200010;

int n,m;
ll l[MaxN],r[MaxN];
pair<pll,int> p[MaxN];
int ans[MaxN];
map<int,int> a;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%I64d%I64d",&l[i],&r[i]);
	for (int i=1;i<=m;++i)
	{
		int x;
		scanf("%I64d",&x);
		a[x]=i;
	}
	priority_queue<pair<pll,int>> Q;
	for (int i=1;i<n;++i)
	{
		p[i]=make_pair(pll(l[i+1]-r[i],r[i+1]-l[i]),i);
		auto q=make_pair(pll(-(r[i+1]-l[i]),l[i+1]-r[i]),i);
		Q.push(q);
	}
	sort(p+1,p+n);
	int i=1,j=1;
	while (!Q.empty())
	{
		auto q=Q.top();
		q.X.X=-q.X.X;
		Q.pop();
		auto it=a.lower_bound(q.X.Y);
		if (it==a.end())
		{
			puts("No");
			return 0;
		}
		if (it->X>q.X.X)
		{
			puts("No");
			return 0;
		}
		ans[q.Y]=it->Y;
		a.erase(it);
	}
	puts("Yes");
	for (int i=1;i<n;++i)
		printf("%d ",ans[i]);
	return 0;
}