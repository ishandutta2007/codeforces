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

int n;
LL a[maxn + 5];

map<pair<int, LL>, LL> f;

LL work(int x, const LL &lim)
{
	if (f.count(mp(x, lim))) return f[mp(x, lim)];
	LL &ret = f[mp(x, lim)];
	if (x == n - 1)
	{
		return ret = (LL)(lim - 1) * (x + 1);
	}
	if (lim <= a[x + 1])
	{
		int l = x + 1, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (a[mid] >= lim) l = mid + 1;
			else r = mid;
		}
		return ret = work(l - 1, lim);
	}
	LL tmp = lim - lim % a[x + 1] - a[x + 1];
	ret = work(x + 1, a[x + 1]) + (LL)tmp * (x + 1);
	if ((lim % a[x + 1]))
		chkmax(ret, work(x + 1, lim % a[x + 1]) + (LL)(tmp + a[x + 1]) * (x + 1)); 
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) cin >> a[i];
	REP(i, 1, n) chkmin(a[i], a[i - 1]);
	cout << work(0, a[0]) << endl;
	return 0;
}