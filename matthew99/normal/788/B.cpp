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

const int maxn = 1000100;

int d[maxn + 5], loop[maxn + 5];

int n, m;

int fa[maxn + 5];
int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) fa[i] = i;
	int cnt_loop = 0;
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		fa[get(u)] = get(v);
		if (u == v) ++cnt_loop, loop[u] = 1;
		else ++d[u], ++d[v];
	}
	vector<int> has;
	REP(i, 0, n) if (d[i] || loop[i]) has.pb(i);
	REP(i, 1, SZ(has)) if (get(has[i]) != get(has[0])) { printf("0\n"); return 0; }
	LL ans = 0;
	REP(i, 0, n) ans += (LL)d[i] * (d[i] - 1) >> 1;
	ans += (LL)cnt_loop * (cnt_loop - 1) >> 1;
	ans += (LL)cnt_loop * (m - cnt_loop);
	cout << ans << endl;
	return 0;
}