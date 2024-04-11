#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int maxn = 4000;

const int Mod = 1e9 + 7;

int f[maxn + 5];

int fpm(LL b, int e, const int &m)
{
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int C[maxn + 5][maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 0, maxn + 5)
	{
		C[i][0] = 1;
		REP(j, 1, i + 1)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	}
	f[0] = 1;
	REP(i, 1, maxn + 5)
	{
		REP(j, 1, i + 1)
			(f[i] += f[i - j] * (LL)C[i - 1][j - 1] % Mod) %= Mod;
	}
	int n;
	scanf("%d", &n);
	int ret = 0;
	REP(i, 0, n)
		(ret += f[i] * (LL)C[n][i] % Mod) %= Mod;
	(ret += Mod) %= Mod;
	printf("%d\n", ret);
	return 0;
}