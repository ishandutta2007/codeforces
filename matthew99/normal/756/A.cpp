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

const int maxn = 200100;

int n;
int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	bool flag = 0;
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		flag ^= x;
	}
	int ans = !flag;
	int cnt = 0;
	static bool vis[maxn + 5];
	memset(vis, 0, sizeof vis);
	REP(i, 0, n) if (!vis[i])
	{
		++cnt;
		int u = i;
		while (!vis[u])
		{
			vis[u] = 1;
			u = a[u];
		}
	}
	if (cnt > 1) ans += cnt;
	printf("%d\n", ans);
	return 0;
}