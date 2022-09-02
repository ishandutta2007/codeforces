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

int n;
int a[maxn + 5];
int b[maxn + 5];

int pos[maxn + 5];
int ans[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	REP(i, 0, n) scanf("%d", b + i), pos[i] = i;
	sort(pos, pos + n, [&](int x, int y) { return b[x] > b[y]; });
	REP(i, 0, n) ans[pos[i]] = a[i];
	REP(i, 0, n) printf("%d ", ans[i]);
	return 0;
}