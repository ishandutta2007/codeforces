#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define SZ(x) (int((x).size()))
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

template<typename T> bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

const int maxn = 1000;

bitset<maxn> appear[maxn + 5], all[maxn + 5];
int f[maxn + 5][maxn + 5];

int n;

int Max[maxn + 5], from[maxn + 5];
bool vis[maxn + 5];

bool leaf[maxn + 5];

bitset<maxn> e[maxn + 5];

inline void add_edge(const int &x, const int &y)
{
	e[x][y] = e[y][x] = 1;
	printf("%d %d\n", x + 1, y + 1);
}

bitset<maxn> ori[maxn + 5];
int sz[maxn + 5];

inline bool cmp(const int &x, const int &y)
{
	return sz[x] < sz[y];
}

inline bool cmp0(const bitset<maxn> &x, const bitset<maxn> &y)
{
	REP(i, 0, n) if (x[i] != y[i]) return x[i] < y[i];
	return 0;
}

int deg[maxn + 5];

inline bool cmp1(const int &x, const int &y)
{
	return deg[x] < deg[y];
}

inline bool check()
{
	REP(i, 0, n) e[i][i] = 1;
	bitset<maxn> ans[maxn + 5];
	REP(i, 0, n)
	{
		ans[i] = 0;
		REP(j, 0, n)
			if (e[i][j]) ans[i] |= e[j];
	}
	sort(all, all + n, cmp0);
	sort(ans, ans + n, cmp0);
	REP(i, 0, n) if (ans[i] != all[i]) return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	static int pos[maxn + 5];
	REP(i, 0, n)
	{
		pos[i] = i;
		static int m;
		scanf("%d", &m);
		REP(j, 0, m)
		{
			static int x;
			scanf("%d", &x), --x;
			ori[i][x] = 1;
		}
		sz[i] = m;
	}
	sort(pos, pos + n, cmp);
	REP(i, 0, n) all[i] = ori[pos[i]];
	REP(i, 0, n)
		REP(j, 0, n)
			appear[j][i] = all[i][j];
	REP(i, 0, n)
		REP(j, 0, i)
			f[i][j] = f[j][i] = (appear[i] & appear[j]).count();
	REP(i, 0, n)
		e[i][i] = 1;
	int lst = 0;
	int Min = oo;
	REP(i, 0, n)
	{
		bitset<maxn> S;
		S = ~S;
		REP(j, 0, n)
			if (all[j][i]) S &= all[j];
		if ((int)S.count() < Min)
		{
			Min = S.count();
			lst = i;
		}
		if (!Min) break;
	}
	if (lst >= n) lst = 0;
	memset(Max, -1, sizeof Max);
	vis[lst] = 1;
	REP(i, 0, n - 1)
	{
		int Maxp = -1;
		REP(j, 0, n) if (!vis[j])
		{
			if (!leaf[lst])
			{
				if (f[lst][j] > Max[j]) Max[j] = f[lst][j], from[j] = lst, leaf[j] = 0;
				else if (f[lst][j] == Max[j]) leaf[j] = 1;
			}
			if (Maxp == -1 || Max[j] > Max[Maxp]) Maxp = j;
		}
		lst = Maxp;
		vis[lst] = 1;
		if (!leaf[Maxp]) add_edge(Maxp, from[Maxp]), ++deg[Maxp], ++deg[from[Maxp]];
	}
	bitset<maxn> nd;
	REP(i, 0, n) if (!leaf[i]) nd[i] = 1;
	memset(vis, 0, sizeof vis);
	vector<pair<int, int> > leaf_ed;
	sort(pos, pos + n, cmp1);
	REP(i, 0, n)
		if (!leaf[pos[i]])
		{
			REP(j, 0, n)
				if (!vis[j] && (all[j] & nd) == e[pos[i]])
				{
					vis[j] = 1;
					bitset<maxn> lyc = all[j] ^ e[pos[i]];
					REP(k, 0, n) if (lyc[k]) 
					{
						printf("%d %d\n", pos[i] + 1, k + 1);
						leaf_ed.pb(mp(pos[i], k));
						REP(k0, 0, n)
							if (!vis[k0] && all[k0][k]) vis[k0] = 1;
					}
					break;
				}
		}
#ifndef ONLINE_JUDGE
	for (auto it : leaf_ed) e[it.x][it.y] = e[it.y][it.x] = 1;
	if (!check()) printf("wrong\n");
#endif
	return 0;
}