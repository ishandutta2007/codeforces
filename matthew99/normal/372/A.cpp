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

const int maxabs = 100000;

const int maxn = 5e5;

int cnt[maxabs + 5];

bool picked[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	vector<int> a;
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		a.pb(x);
	}
	sort(ALL(a));
	int l = 0, r = n >> 1;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		vector<int> u;
		vector<int> v;
		REP(i, 0, mid) u.pb(a[i]);
		REP(i, n - mid, n) v.pb(a[i]);
		sort(ALL(u));
		sort(ALL(v));
		bool flag = 1;
		REP(i, 0, mid) if ((u[i] << 1) > v[i])
		{
			flag = 0;
			break;
		}
		if (flag) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", n - l);
	return 0;
}