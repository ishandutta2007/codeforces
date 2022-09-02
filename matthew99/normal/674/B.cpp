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
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == 4 || k <= n)
	{
		printf("-1\n");
		return 0;
	}
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d), --a, --b, --c, --d;
	vector<int> A, B;
	A.pb(a), A.pb(c);
	REP(i, 0, n) if (i != a && i != b && i != c && i != d) A.pb(i);
	A.pb(d), A.pb(b);
	B.pb(c), B.pb(a);
	REP(i, 0, n) if (i != a && i != b && i != c && i != d) B.pb(i);
	B.pb(b), B.pb(d);
	for (auto x : A) printf("%d ", x + 1);
	printf("\n");
	for (auto x : B) printf("%d ", x + 1);
	printf("\n");
	return 0;
}