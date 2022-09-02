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

const int maxn = 100000;

int n, k;
char s[maxn + 5];

int sum[maxn + 5];

inline bool check(int x)
{
	REP(i, 0, n) if (s[i] != '1' && sum[min(n, i + x + 1)] - sum[max(0, i - x)] - 1 >= k) return 1; 
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	sum[0] = 0;
	REP(i, 0, n) sum[i + 1] = sum[i] + (s[i] == '0');
	int l = 0, r = n;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}