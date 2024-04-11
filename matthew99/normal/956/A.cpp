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

const int maxn = 60;

int n, m;
char g[maxn + 5][maxn + 5];
int pa[(maxn << 1) + 5];

int get(int x) { return pa[x] == x ? x : pa[x] = get(pa[x]); }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%s", g[i]);
	REP(i, 0, n + m) pa[i] = i;
	REP(i, 0, n) REP(j, 0, m)
		if (g[i][j] == '#') pa[get(i)] = get(n + j);
	REP(i, 0, n) REP(j, 0, m)
		if ((g[i][j] == '#') ^ (get(i) == get(n + j)))
		{
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}