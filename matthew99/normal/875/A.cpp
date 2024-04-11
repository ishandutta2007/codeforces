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

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	vector<int> ans;
	REP(i, max(1, n - 1000), n + 1)
	{
		int u = i;
		int tmp = i;
		REP(j, 0, 10)
		{
			tmp += u % 10;
			u /= 10;
		}
		if (tmp == n) ans.pb(i);
	}
	printf("%d\n", SZ(ans));
	for (auto u : ans) printf("%d\n", u);
	return 0;
}