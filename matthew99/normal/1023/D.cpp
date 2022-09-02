#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200100, maxm = 200100;

int n, m;
int a[maxn + 5];

vector<int> all[maxm + 5];

int fen[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i);
	bool found = 0;
	REP(i, 0, n) if (a[i] == m) found = 1;
	if (!found)
	{
		REP(i, 0, n) if (!a[i])
		{
			a[i] = m;
			found = 1;
			break;
		}
		if (!found)
		{
			puts("NO");
			exit(0);
		}
	}
	int cur = 1;
	REP(i, 0, n) 
	{
		if (a[i]) cur = a[i]; else a[i] = cur; 
		all[a[i]].pb(i);
	}
	memset(fen, 0, sizeof fen);
	REP(i, 1, m + 1) if (SZ(all[i]))
	{
		int sum = 0;
		for (int j = all[i][0] + 1; j <= n; j += j & -j) sum += fen[j];
		for (int j = all[i].back() + 1; j <= n; j += j & -j) sum -= fen[j];
		if (sum) puts("NO"), exit(0);
		for (auto u : all[i]) for (int j = u + 1; j > 0; j -= j & -j) ++fen[j];
	}
	puts("YES");
	REP(i, 0, n) printf("%d ", a[i]);
	printf("\n");
	return 0;
}