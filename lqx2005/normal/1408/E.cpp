#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
struct edge
{
	int fro, to, co;
}e[N << 1];
int m, n, tot = 0;
int a[N], b[N], fa[N];
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int u, int v)
{
	u = find(u), v = find(v);
	if(u == v) return;
	fa[u] = v;
	return;
}

int cmp(edge a, edge b)
{
	return a.co > b.co;
}
void addedge(int u, int v, int w)
{
	e[++tot] = edge{u, v, w};
	return;
}
ll MST()
{
	sort(e + 1, e + tot + 1, cmp);
	rep(i, 1, n + m) fa[i] = i;
	ll ans = 0;
	rep(i, 1, tot)
	{
		int u = e[i].fro, v = e[i].to;
		if(find(u) == find(v)) continue;
		merge(u, v);		
		ans += e[i].co;
	}
	return ans;
}
int main()
{
	scanf("%d%d", &m, &n);
	rep(i, 1, m) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	int s;
	ll all = 0;
	rep(i, 1, m)
	{
		scanf("%d", &s);
		int to;
		rep(j, 1, s) 
		{
			scanf("%d", &to);
			addedge(i, to + m, a[i] + b[to]);
			all += a[i] + b[to];
		}
	}
	printf("%lld\n", all - MST());
	return 0;
}