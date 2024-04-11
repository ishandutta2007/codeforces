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

const int maxn = 100010;
const int maxk = 100010;

vector<int> a[(maxn << 1) + 5], b[(maxn << 1) + 5];

LL ans[maxk + 5];
pair<int, int> p[maxk + 5];

const int walk[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, K;
	scanf("%d%d%d", &n, &m, &K);
	memset(ans, -1, sizeof ans);
	REP(i, 0, K)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		p[i] = mp(u, v);
		a[u - v + maxn].pb(i);
		b[u + v].pb(i);
	}
	int x = 0, y = 0, now = 0;
	LL t = 0;
	while (1)
	{
		if (now & 1) 
		{
			for (auto uu : b[x + y]) if (!~ans[uu]) ans[uu] = t + abs(p[uu].x - x);
			b[x + y].clear();
		}
		else
		{
			for (auto uu : a[x - y + maxn]) if (!~ans[uu]) ans[uu] = t + abs(p[uu].x - x);
			a[x - y + maxn].clear();
		}
		int u = walk[now][0], v = walk[now][1];
		int tx = (u > 0 ? n - x : x), ty = (v > 0 ? m - y : y);
		if (tx == ty) break;
		if (tx < ty)
		{
			if (now & 1) (now += 1) &= 3;
			else (now += 3) &= 3;
			x += tx * u, y += tx * v;
			t += tx;
		}
		else
		{
			if (now & 1) (now += 3) &= 3;
			else (now += 1) &= 3;
			x += ty * u, y += ty * v;
			t += ty;
		}
	}
	REP(i, 0, K) printf("%I64d\n", ans[i]);
	return 0;
}