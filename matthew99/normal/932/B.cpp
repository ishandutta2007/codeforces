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

int g(int x)
{
	if (x < 10) return x;
	int ret = 1;
	while (x)
	{
		if (x % 10) ret *= x % 10;
		x /= 10;
	}
	return g(ret);
}

vector<int> all[10];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 1, 1.1e6)
		all[g(i)].pb(i);
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x), ++r;
		printf("%d\n", lower_bound(ALL(all[x]), r) - lower_bound(ALL(all[x]), l)); 
	}
	return 0;
}