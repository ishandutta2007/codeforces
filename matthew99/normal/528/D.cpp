#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <set>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 524288;

int n, m, k;
char S[maxn + 5], s[maxn + 5];

int dis[4][maxn + 5];

int nxt[maxn + 5];

char chr[4] = {'A', 'C', 'G', 'T'};
int id[256];

void work(const int &x)
{
	int lst = -oo;
	REP(i, 0, n)
	{
		if (S[i] == chr[x]) lst = i;
		dis[x][i] = min(oo, i - lst);
	}
	lst = oo;
	for (int i = n - 1; i >= 0; --i)
	{
		dis[x][i] = min(dis[x][i], lst - i);
		if (S[i] == chr[x]) lst = i;
	}
}

const int Mod = 998244353;
const int fft_g = 3;

inline LL fpm(LL b, int e, const int &m)
{
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int w[maxn + 5];

int bitrev[maxn + 5];

void fft(int *a, const int &n)
{
	REP(i, 0, n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
	for (int i = 1, len = n >> 1; i < n; i <<= 1, len >>= 1)
		for (int j = 0; j < n; j += (i << 1))
		{
			int *l = a + j, *r = a + j + i;
			int *w0 = w;
			for (int k = 0; k < i; ++k, ++l, ++r, w0 += len)
			{
				int s = *l, t = (LL)*r * *w0 % Mod;
				*l = (s + t) % Mod, *r = (s - t) % Mod;
			}
		}
}

bool OK[maxn + 5];

int is[4][maxn + 5];
int ok[4][maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", S);
	scanf("%s", s);
	reverse(S, S + n);
	REP(i, 0, n) OK[i] = 1;
	REP(i, 0, 4) 
	{
		work(i);
		REP(j, 0, n) ok[i][j] = dis[i][j] <= k;
	}
	id['A'] = 0;
	id['C'] = 1;
	id['G'] = 2;
	id['T'] = 3;
	int cnt[4] = {0};
	REP(i, 0, m) is[id[(int)s[i]]][i] = 1, ++cnt[id[(int)s[i]]];
	int N = n + m, L = 0;
	while (N & (N - 1)) ++N;
	for (L = 0; (1 << L) < N; ++L);
	REP(i, 0, N) bitrev[i] = (bitrev[i >> 1] >> 1) | ((i & 1) << (L - 1));;
	int step = fpm(fft_g, (Mod - 1) / N, Mod);
	w[0] = 1;
	REP(i, 0, N) w[i + 1] = (LL)w[i] * step % Mod;
	REP(i, 0, 4)
	{
		fft(ok[i], N);
		fft(is[i], N);
		REP(j, 0, N) is[i][j] = (LL)is[i][j] * ok[i][j] % Mod;
		reverse(w + 1, w + N);
		fft(is[i], N);
		int tmp = (LL)cnt[i] * N % Mod;
		REP(j, 0, N) if ((is[i][j] + Mod) % Mod != (tmp + Mod) % Mod) OK[j] = 0;
		reverse(w + 1, w + N);
	}

	int ans = 0;
	REP(i, 0, n) ans += OK[i];
	printf("%d\n", ans);
	return 0;
}