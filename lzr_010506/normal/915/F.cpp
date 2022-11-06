#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1000005;

int n, a[N];
vi G[N];
pii seq[N];
ll res;
int fa[N], siz[N];
bool tk[N];

int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void Union(int a, int b, ll val)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	res += val * siz[a] * siz[b];
	siz[a] += siz[b];
	fa[b] = a;
}

void Solve()
{
	fill(tk, tk + n + 1, false);
	rep(i, 1, n)
	{
		int v = seq[i].Y;
		tk[v] = 1;
		fa[v] = v;
		siz[v] = 1;
		int nn = sz(G[v]) - 1;
		rep(j, 0, nn)
		{
			int u = G[v][j];
			if (tk[u]) Union(v, u, seq[i].X);
		}
	}
}

int main()
{
	n = read();
	rep(i, 1, n)
	{
		a[i] = read();
		seq[i] = mp(a[i], i);
	}
	rep(i, 1, n - 1)
	{
		int a = read(), b = read();
		G[a].pb(b);
		G[b].pb(a);
	}
	sort(seq + 1, seq + n + 1);
	Solve();
	rep(i, 1, n)
		seq[i].X = -seq[i].X;
	sort(seq + 1, seq + n + 1);
	Solve();
	cout << res << endl;
	return 0;
}