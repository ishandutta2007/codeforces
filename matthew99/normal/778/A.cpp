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

const int maxn = 200100;

int n_t, n_p;
char p[maxn + 5], t[maxn + 5];
int a[maxn + 5];

bool ok[maxn + 5];

inline bool check(int x)
{
	memset(ok, 1, sizeof ok);
	REP(i, 0, x) ok[a[i]] = 0;
	int j = 0;
	REP(i, 0, n_t) if (ok[i])
	{
		if (t[i] == p[j]) ++j;
		if (j == n_p) return 1;
	}
	return 0;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", t);
	scanf("%s", p);
	n_t = strlen(t);
	n_p = strlen(p);
	REP(i, 0, n_t) scanf("%d", a + i), --a[i];
	int l = 0, r = n_t;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}