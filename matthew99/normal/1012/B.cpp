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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 400100;

int n, m, K;

int fa[maxn + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, n + m) fa[i] = i;
	REP(i, 0, K)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		fa[get(u)] = get(n + v);
	}
	int ans = 0;
	REP(i, 0, n + m) if (fa[i] == i) ++ans;
	--ans;
	printf("%d\n", ans);
	return 0;
}