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

const int maxn = 5100;

int cnt[maxn + 5];

int n;
int a[maxn + 5];

int ans[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	REP(i, 0, n)
	{
		memset(cnt, 0, sizeof cnt);
		int Maxp = 0;
		REP(j, i, n)
		{
			++cnt[a[j]];
			if (cnt[a[j]] > cnt[Maxp] || (cnt[a[j]] == cnt[Maxp] && a[j] < Maxp)) Maxp = a[j];
			++ans[Maxp];
		}
	}
	REP(i, 0, n) printf("%d ", ans[i]);
	return 0;
}