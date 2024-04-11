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

const int maxn = 300100;

int T;

int n;
int a[maxn + 5];

int len[maxn + 5];
int End[maxn + 5];

map<int, int> lst[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		REP(i, 0, n) scanf("%d", a + i);
		REP(i, 0, n + 5) lst[i].clear(), End[i] = i, len[i] = 0;
		LL ans = 0;
		REP(i, 1, n)
		{
			lst[End[i]][a[i - 1]] = i - 1;
			if (lst[End[i]].count(a[i]))
			{
				int tmp = lst[End[i]][a[i]];
				End[i + 1] = End[tmp];
				len[i + 1] = len[tmp] + 1;
				ans += len[i + 1];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}