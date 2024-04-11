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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

int n, m;

int pw7[10];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pw7[0] = 1;
	REP(i, 0, 9) pw7[i + 1] = pw7[i] * 7;
	scanf("%d%d", &n, &m);
	int numn = 0, numm = 0;
	int u = n - 1;
	while (u) ++numn, u /= 7;
	if (!numn) numn = 1;
	u = m - 1;
	while (u) ++numm, u /= 7;
	if (!numm) numm = 1;
	if (numn + numm > 7) printf("0\n");
	else
	{
		static bool ok[7];
		int ans = 0;
		REP(i, 0, n)
		{
			REP(j, 0, m)
			{
				memset(ok, 0, sizeof ok);
				REP(u, 0, numn) ok[i / pw7[u] % 7] = 1;
				REP(u, 0, numm) ok[j / pw7[u] % 7] = 1;
				int cnt = 0;
				REP(u, 0, 7) if (ok[u]) ++cnt;
				if (cnt == numn + numm) ++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}