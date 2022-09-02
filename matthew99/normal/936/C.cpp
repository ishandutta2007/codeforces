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

const int maxn = 2010;

int n;
char a[maxn + 5], b[maxn + 5];

vector<int> ans;

inline void work(int x)
{
	ans.pb(x);
	rotate(a, a + n - x, a + n);
	reverse(a, a + x);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s%s", a, b);
	REP(i, 0, n)
	{
		int p = -1;
		REP(j, i, n) if (a[j] == b[i])
		{
			p = j;
			break;
		}
		if (!~p)
		{
			printf("-1\n");
			return 0;
		}
		work(n);
		work(p);
		work(1);
	}
	work(n);
	REP(i, 0, n) assert(a[i] == b[i]);
	printf("%d\n", SZ(ans));
	for (auto u : ans) printf("%d ", u);
	return 0;
}