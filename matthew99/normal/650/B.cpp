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

const int maxn = 500000;

int n, a, b, T;

char s[maxn + 5];

int t[maxn + 5], need[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &a, &b, &T);
	scanf("%s", s);
	REP(i, 0, n)
	{
		if (s[i] == 'w') t[i] = b + 1;
		else t[i] = 1;
	}
	int ans = 0;
	REP(i, 0, 2)
	{
		reverse(t + 1, t + n);
		need[n] = 0;
		for (int i = n - 1; i >= 0; --i) need[i] = need[i + 1] + t[i] + a;
		int j = 0;
		int used = 0;
		REP(i, 0, n)
		{
			used += t[i];
			if (used > T) break;
			while (j <= i || (j < n && used + i * a + need[j] > T)) ++j;
			chkmax(ans, i + 1 + n - j);
			used += a;
		}
	}
	printf("%d\n", ans);
	return 0;
}