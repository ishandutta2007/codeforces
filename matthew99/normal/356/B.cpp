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

const int maxn = 1000000;

LL n, m;
char a[maxn + 5], b[maxn + 5];
int na, nb;

int w[maxn + 5];

int sum[maxn + 5][26];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%I64d%I64d", &n, &m);
	scanf("%s%s", a, b);
	na = strlen(a), nb = strlen(b);
	LL d = __gcd(na, nb);
	LL vez = n / (nb / d);
	LL ans = n * na;
	REP(i, 0, nb) ++sum[i % d][b[i] - 'a'];
	REP(i, 0, na) ans -= sum[i % d][a[i] - 'a'] * vez;
	printf("%I64d\n", ans);
	return 0;
}