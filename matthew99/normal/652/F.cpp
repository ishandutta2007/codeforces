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

const int maxn = 300000;

int n, m;
LL t;

int p[maxn + 5], d[maxn + 5];

int pos[maxn + 5];

inline bool cmp(int x, int y) { return p[x] < p[y]; }

int ans[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%I64d", &n, &m, &t);
	static char s[5];
	REP(i, 0, n) scanf("%d%s", p + i, s), --p[i], d[i] = s[0] == 'R', pos[i] = i;
	sort(pos, pos + n, cmp);
	static int a[maxn + 5];
	int sft = 0;
	REP(i, 0, n) if (d[i]) a[i] = (p[i] + t) % m, (sft += ((p[i] + t - a[i]) / m) % n) %= n; else a[i] = ((p[i] - t) % m + m) % m, (sft += ((p[i] - t - a[i]) / m) % n) %= n;
	(sft += n) %= n;
	sort(a, a + n);
	rotate(a, a + sft, a + n);
	REP(i, 0, n) ans[pos[i]] = a[i];
	REP(i, 0, n) printf("%d ", ans[i] + 1);
	return 0;
}