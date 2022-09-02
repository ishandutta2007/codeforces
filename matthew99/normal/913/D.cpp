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

const int maxn = 200100;

int n, T;
pair<int, pair<int, int> > a[maxn + 5];

vector<int> ans;

inline bool check(int lim)
{
	vector<pair<int, int> > all;
	REP(i, 0, n) if (a[i].x >= lim) all.pb(a[i].y);
	if (SZ(all) < lim) return 0;
	sort(ALL(all));
	ans.clear();
	LL ret = 0;
	REP(i, 0, lim) ret += all[i].x, ans.pb(all[i].y);
	return ret <= T;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &T);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y.x), a[i].y.y = i;
	sort(a, a + n);
	int l = 0, r = n;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	check(l);
	printf("%d\n%d\n", l, l);
	for (auto u : ans) printf("%d ", u + 1);
	return 0;
}