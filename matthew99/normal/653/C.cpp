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

const int max0 = 10, maxn = 150000;

int n;
int a[maxn + 5];

bool ok[maxn + 5], in[maxn + 5];

int tot = 0;

inline bool get_ok(int i)
{
	if (i & 1) return a[i] > a[i + 1];
	return a[i] < a[i + 1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	set<int> all;
	int tot = 0;
	REP(i, 0, n - 1)
	{
		ok[i] = get_ok(i);
		if (!ok[i]) all.insert(i), in[i] = 1, all.insert(i + 1), in[i + 1] = 1;
		tot += !ok[i];
	}
	int ans = 0;
	assert(tot);
	if (tot > max0) printf("0\n");
	else
	{
		for (auto x : all)
		{
			int now = tot;
			REP(u, x - 1, x + 1) if (u >= 0 && u < n - 1) now -= !ok[u];
			REP(y, 0, n) if (y != x)
			{
				if (y < x && in[y] && in[x]) continue;
				int tmp = now;
				REP(u, y - 1, y + 1) if (u != x - 1 && u != x && u >= 0 && u < n - 1) tmp -= !ok[u];
				if (!tmp)
				{
					swap(a[x], a[y]);
					bool flag = 1;
					REP(u, x - 1, x + 1) if (u >= 0 && u < n - 1 && !get_ok(u)) flag = 0;
					REP(u, y - 1, y + 1) if (u >= 0 && u < n - 1 && !get_ok(u)) flag = 0;
					ans += flag;
					swap(a[x], a[y]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}