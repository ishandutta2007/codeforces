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

const int maxn = 200100, maxm = 200100;

int n, m;

pair<int, pair<int, int> > ed[maxm + 5];

int fa[maxn + 5];
bool has[maxn + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) fa[i] = i, has[i] = 0;
	REP(i, 0, m)
	{
		scanf("%d%d%d", &ed[i].y.x, &ed[i].y.y, &ed[i].x);
		--ed[i].y.x, --ed[i].y.y;
	}
	sort(ed, ed + m);
	reverse(ed, ed + m);
	int ans = 0;
	REP(i, 0, m)
	{
		int u = get(ed[i].y.x), v = get(ed[i].y.y);
		if (u != v && !(has[u] && has[v]))
		{
			ans += ed[i].x;
			has[v] |= has[u];
			fa[u] = v;
		}
		else if (!has[u])
		{
			ans += ed[i].x;
			has[u] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}