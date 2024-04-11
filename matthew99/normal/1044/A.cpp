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

const int maxn = 100100;

int n, m;
vector<int> a, b;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		a.pb(x);
	}
	REP(i, 0, m)
	{
		int l, r, y;
		scanf("%d%d%d", &l, &r, &y);
		if (l == 1)
		{
			b.pb(r);
		}
	}
	sort(ALL(a));
	sort(ALL(b));
	int ptr = 0;
	a.pb(1000000000);
	int ans = oo;
	REP(i, 0, SZ(a))
	{
		while (ptr < SZ(b) && b[ptr] < a[i]) ++ptr;
		chkmin(ans, i + SZ(b) - ptr);
	}
	printf("%d\n", ans);
	return 0;
}