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

const int Mod = 1e9 + 7;
const int maxc = 1000;

int n;
int c[maxc + 5];
int C[maxc + 5][maxc + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 0, maxc + 1)
	{
		C[i][0] = 1;
		REP(j, 1, i + 1) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
	}
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", c + i);
	int ans = 1;
	int cnt = c[0];
	REP(i, 1, n)
	{
		cnt += c[i];
		ans = LL(ans) * C[cnt - 1][c[i] - 1] % Mod;
	}
	printf("%d\n", ans);
	return 0;
}