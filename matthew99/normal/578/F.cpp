#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100;

const int max0 = 1000000, max1 = 1000;

int n, m, Mod;
char s[maxn + 5][maxn + 5];

int ans = 0;

int fa[max0 + 5], rk[max0 + 5];

int f[max1 + 5][max1 + 5];

inline int get(const int &x)
{
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}

inline void work(const bool &type)
{
	REP(i, 0, max0) fa[i] = i, rk[i] = 0;
	vector<pair<int, int> > all;
	REP(i, 0, n)
		REP(j, 0, m)
		{
			int tmp0 = type ^ ((i + j) & 1);
			if (s[i][j] == '*')
			{
				int u, v;
				if (tmp0)
				{
					u = i * (m + 1) + j;
					v = (i + 1) * (m + 1) + j + 1;
				}
				else
				{
					u = i * (m + 1) + j + 1;
					v = (i + 1) * (m + 1) + j;
				}
				all.pb(mp(u, v));
			}
			else if (s[i][j] == '\\' && tmp0)
			{
				int u = i * (m + 1) + j;
				int v = (i + 1) * (m + 1) + j + 1;
				u = get(u), v = get(v);
				if (u == v) return;
				if (rk[u] < rk[v]) swap(u, v);
				fa[v] = u;
				rk[u] += rk[u] == rk[v];
			}
			else if (s[i][j] == '/' && !tmp0)
			{
				int u = i * (m + 1) + j + 1;
				int v = (i + 1) * (m + 1) + j;
				u = get(u), v = get(v);
				if (u == v) return;
				if (rk[u] < rk[v]) swap(u, v);
				fa[v] = u;
				rk[u] += rk[u] == rk[v];
			}
		}

	static int hash[max0 + 5];
	int N = 0;

	memset(hash, -1, sizeof hash);

	memset(f, 0, sizeof f);

	for (auto it : all)
	{
		int u = it.x, v = it.y;
		u = get(u), v = get(v);
		if (u == v) continue;
		if (hash[u] == -1) hash[u] = N++;
		if (hash[v] == -1) hash[v] = N++;
		u = hash[u], v = hash[v];
		++f[u][u], --f[u][v];
		++f[v][v], --f[v][u];
	}

	for (auto it : all)
	{
		int u = it.x, v = it.y;
		u = get(u), v = get(v);
		if (u == v) continue;
		if (rk[u] < rk[v]) swap(u, v);
		fa[v] = u;
		rk[u] += rk[u] == rk[v];
	}

	int lst = -1;

	REP(i, 0, n + 1)
		REP(j, 0, m + 1)
		{
			if (((i + j) & 1) != type)
			{
				int tmp = get(i * (m + 1) + j);
				if (lst == -1) lst = tmp;
				else if (tmp != lst) return;
			}
		}

	--N;

	REP(i, 0, N) REP(j, 0, N) f[i][j] %= Mod;

	static int pos[maxn + 5];

	int ret = 1;

	REP(i, 0, N) pos[i] = i;

	REP(i, 0, N)
	{
		for (int j = i; j < N; ++j)
		{
			if (f[pos[j]][i])
			{
				swap(pos[i], pos[j]);
				if (i != j) ret = -ret;
				break;
			}
		}
		if (!f[pos[i]][i]) return;
		REP(j, i + 1, N)
		{
			if (f[pos[j]][i])
			{
				pair<int, int> u = mp(1, 0), v = mp(0, 1);
				int x = f[pos[i]][i], y = f[pos[j]][i];
				while (y)
				{
					int tmp = x / y;
					(u.x -= (LL)v.x * tmp % Mod) %= Mod;
					(u.y -= (LL)v.y * tmp % Mod) %= Mod;
					x -= tmp * y;
					ret = -ret;
					swap(x, y);
					swap(u, v);
				}
				REP(k, i, N)
				{
					int x = f[pos[i]][k], y = f[pos[j]][k];
					f[pos[i]][k] = ((LL)u.x * x + (LL)u.y * y) % Mod;
					f[pos[j]][k] = ((LL)v.x * x + (LL)v.y * y) % Mod;
				}
			}
		}
		ret = (LL)ret * f[pos[i]][i] % Mod;
	}
	(ans += ret) %= Mod;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &Mod);
	REP(i, 0, n)
		scanf("%s", s[i]);
	REP(i, 0, 2) work(i);
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}