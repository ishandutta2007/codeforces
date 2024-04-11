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

const int max0 = 18, maxn = 200100;

int n;
pair<int, int> a[maxn + 5];

int fen[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	vector<int> v;
	REP(i, 0, n)
	{
		scanf("%d%d", &a[i].y, &a[i].x);
		v.pb(a[i].y);
	}
	sort(a, a + n);
	sort(ALL(v));
	REP(i, 0, n) a[i].y = lower_bound(ALL(v), a[i].y) - v.begin();
	LL ans = 0;
	set<int> all;
	for (int i = n - 1; i >= 0; --i)
	{
		int lim = -1;
		if (i > 0 && a[i].x == a[i - 1].x) lim = a[i - 1].y;

		if (!all.count(a[i].y))
		{
			all.insert(a[i].y);
			for (int j = a[i].y + 1; j <= n; j += j & -j) ++fen[j];
		}

		int left = 0;
		for (int j = a[i].y + 1; j > 0; j -= j & -j) left += fen[j];
		for (int j = lim + 1; j > 0; j -= j & -j) left -= fen[j];
		int right = SZ(all);
		for (int j = a[i].y; j > 0; j -= j & -j) right -= fen[j];

		ans += (LL)left * right;
	}
	cout << ans << endl;
	return 0;
}