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

const int maxx = 1.01e6;

bool pr[maxx + 5];
bool ok[maxx + 5];

int x;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &x);
	memset(pr, 1, sizeof pr);
	pr[1] = 0;
	for (int i = 2; i <= x; ++i)
		for (int j = i << 1; j <= x; j += i)
			pr[j] = 0;
	vector<int> fac;
	REP(i, 2, x + 1) if (pr[i] && !(x % i)) fac.pb(i);
	int Min = oo;
	REP(i, 3, x + 1)
	{
		for (auto j : fac)
		{
			if (((i + j - 1) / j) * j == x)
			{
				ok[i] = 1;
			}
		}
		if (ok[i]) chkmin(Min, i);
	}
	int ans = oo;
	REP(i, 2, Min) if (pr[i])
	{
		int tmp = ((Min - 1) / i) * i + 1;
		if ((Min + i - 1) / i * i <= x) chkmin(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}