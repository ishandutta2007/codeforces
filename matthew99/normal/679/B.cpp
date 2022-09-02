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

map<LL, pair<int, LL> > f;

inline pair<int, LL> get(const LL &x)
{
	if (!x) return mp(0, 0LL);
	if (f.count(x)) return f[x];
	auto &ret = f[x];
	LL tmp = pow(x, 1. / 3) + 2;
	while (tmp * tmp * tmp > x) --tmp;
	tmp *= tmp * tmp;
	ret = get(x - tmp);
	++ret.x;
	ret.y += tmp;
	chkmax(ret, get(tmp - 1));
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	LL x;
	cin >> x;
	pair<int, LL> tmp = get(x);
	cout << tmp.x << ' ' << tmp.y << endl;
	return 0;
}