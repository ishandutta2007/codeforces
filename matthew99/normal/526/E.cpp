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
#include <climits>

#define REP(i, a, b) for (register int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (register int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

#ifdef _WIN32
#define Rand() ((rand() << 15) + rand())
#else
#define Rand() rand()
#endif

using namespace std;

const int oo = 0x3f3f3f3f;

typedef long long LL;

const int maxn = 2000000, max0 = 10000000;

int n;
int a[maxn + 5];

int now[maxn + 5];

vector<int> child;

int fa[maxn + 5];

inline int get(int x)
{
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int nq;
	scanf("%d%d", &n, &nq);
	REP(i, 0, n) scanf("%d", a + i), a[i + n] = a[i];
	n <<= 1;
	REP(i, 0, nq)
	{
		register LL b;
		static int nxt[maxn + 5], h[maxn + 5];
		scanf("%I64d", &b);
		register int ans = oo;
		register int j = 0;
		register LL sum = 0;
		fa[n] = n;
		REP(i, 0, n)
		{
			fa[i] = i;
			while (j < n && sum + a[j] <= b) sum += a[j++];
			nxt[i] = j;
			if (j > i) sum -= a[i];
			else j = i + 1;
		}
		for (int i = n - 1; i >= 0; --i)
			h[i] = h[nxt[i]] + 1;
		REP(i, 0, n >> 1)
		{
			while (get(i) < i + (n >> 1)) fa[get(i)] = nxt[get(i)];
			if (get(i) >= i + (n >> 1)) ans = min(ans, h[i] - h[get(i)]);
		}
		printf("%d\n", ans);
	}
	return 0;
}