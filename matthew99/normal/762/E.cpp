#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
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

const int maxf = 10010;

const int maxn = 100100;

int n, K;

pair<int, int> a[maxn + 5];
int f[maxn + 5];

vector<int> all[maxf + 5];

LL ans = 0;

int m;
int fen[maxn + 5];

inline void add(int x)
{
	for (int i = x + 1; i <= m; i += i & -i) ++fen[i];
}

inline int query(int x)
{
	int ret = 0;
	for (int i = x; i; i -= i & -i) ret += fen[i];
	return ret;
}

inline void work(int now)
{
	vector<int> u, v;
	REP(i, max(0, now - K), min(maxf, now + K + 1)) for (auto &j : all[i]) u.pb(j);
	m = SZ(u);
	sort(ALL(u), [&](int x, int y) { return a[x].x < a[y].x; });
	REP(i, 0, m) v.pb(i);
	sort(ALL(v), [&](int x, int y) { return a[u[x]].x + a[u[x]].y < a[u[y]].x + a[u[y]].y; });
	memset(fen, 0, sizeof(fen[0]) * m);
	int j = 0;
	REP(i, 0, m) if (f[u[i]] == now)
	{
		while (a[u[v[j]]].x + a[u[v[j]]].y < a[u[i]].x) 
		{
			add(v[j]);
			++j;
		}
		int l = 0, r = i;
		int val = a[u[i]].x - a[u[i]].y;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (a[u[mid]].x < val) l = mid + 1;
			else r = mid;
		}
		ans += (i - l) - (query(i) - query(l));
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n)
	{
		scanf("%d%d%d", &a[i].x, &a[i].y, f + i), --f[i];
		all[f[i]].pb(i);
	}
	REP(i, 0, maxf) work(i);
	cout << ans << endl;
	return 0;
}