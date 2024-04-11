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

const int Mod = 1e9 + 7;

const int maxn = 2000000, maxk = 26;

int n, k;

int lst[maxk];

int sum[maxn + 5];

int m;
char s[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	m = strlen(s);
	REP(i, 0, 26) lst[i] = 0;
	sum[0] = 0;
	sum[1] = 1;
	int now = 1;
	REP(i, 0, m + n)
	{
		int u = -1;
		if (i < m) u = s[i] - 'a';
		else REP(j, 0, k) if (!~u || lst[j] < lst[u]) u = j;
		int tmp = (now - sum[lst[u]]) % Mod;	
		(now += tmp) %= Mod;
		lst[u] = i + 1;
		sum[i + 2] = now;
	}
	(now += Mod) %= Mod;
	printf("%d\n", now);
	return 0;
}