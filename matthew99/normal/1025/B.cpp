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

const int maxn = 150100;

int n;
pair<int, int> a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> test;
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
	{
		int u = a[0].x;
		for (int i = 2; i * i <= u; ++i)
			if (!(u % i))
			{
				test.pb(i);
				while (!(u % i)) u /= i;
			}
		if (u > 1) test.pb(u);
	}
	{
		int u = a[0].y;
		for (int i = 2; i * i <= u; ++i)
			if (!(u % i))
			{
				test.pb(i);
				while (!(u % i)) u /= i;
			}
		if (u > 1) test.pb(u);
	}
		
	for (auto i : test)
	{
		bool failed = 0;
		REP(j, 0, n) if (a[j].x % i && a[j].y % i) { failed = 1; break; }
		if (!failed)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}