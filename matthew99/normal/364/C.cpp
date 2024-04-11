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

vector<int> ans{1}, pr{2, 3, 5, 7, 11};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (auto p : pr)
	{
		if (SZ(ans) > n) break;
		for (int i = 0; i < SZ(ans); ++i) if ((LL)ans[i] * p <= 2 * n * n) ans.pb(ans[i] * p);
	}
	reverse(ALL(ans));
	ans.resize(n);
	for (auto x : ans) printf("%d ", x);
	return 0;
}