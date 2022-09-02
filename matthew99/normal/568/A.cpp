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

const int maxn = 2e6;

bool notprime[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	notprime[1] = 1;
	for (int i = 2; i <= maxn; ++i)
		if (!notprime[i])
			for (int j = i << 1; j <= maxn; j += i)
				notprime[j] = 1;
	int p, q;
	scanf("%d%d", &p, &q);
	int pi = 0, rub = 0;
	int ans = -1;
	for (int i = 1; i <= maxn; ++i)
	{
		int a[10];
		int x = i;
		int cnt = 0;
		while (x) a[cnt++] = x % 10, x /= 10;
		bool flag = 1;
		for (int j = 0, k = cnt - 1; j < k; ++j, --k)
			if (a[j] != a[k]) 
			{
				flag = 0;
				break;
			}
		pi += !notprime[i];
		rub += flag;
		if ((LL)pi * q <= (LL)rub * p)
		{
			ans = max(ans, i);
		}
	}
	if (ans < 0) printf("Palindromic tree is better than splay tree\n");
	else printf("%d\n", ans);
	return 0;
}