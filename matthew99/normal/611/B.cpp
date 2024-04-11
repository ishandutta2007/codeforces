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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<LL> all;
	REP(i, 2, 61)
	{
		LL tmp = (1LL << i) - 1;
		REP(j, 0, i - 1) all.pb(tmp - (1LL << j));
	}
	sort(ALL(all));
	all.resize(unique(ALL(all)) - all.begin());
	LL a, b;
	scanf("%I64d%I64d", &a, &b);
	printf("%d\n", upper_bound(ALL(all), b) - lower_bound(ALL(all), a));
	return 0;
}