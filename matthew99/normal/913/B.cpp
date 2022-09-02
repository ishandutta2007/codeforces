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

const int maxn = 1010;

int n;
int fa[maxn + 5];

int cnt[maxn + 5];

bool leaf[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	fa[0] = -1;
	REP(i, 1, n) scanf("%d", fa + i), --fa[i];
	REP(i, 0, n) leaf[i] = 1, cnt[i] = 0;
	REP(i, 0, n) if (!~fa[i]) leaf[i] = 0;
	REP(i, 0, n) if (~fa[i]) leaf[fa[i]] = 0;
	REP(i, 0, n) if (~fa[i] && leaf[i]) ++cnt[fa[i]];
	REP(i, 0, n) if (!leaf[i] && cnt[i] < 3)
	{
		puts("No");
		exit(0);
	}
	puts("Yes");
	return 0;
}