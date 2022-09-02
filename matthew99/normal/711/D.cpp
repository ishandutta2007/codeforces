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

const int Mod = 1e9 + 7;

const int maxn = 200100;

int n;
int a[maxn + 5];

int lst[maxn + 5];
int pw[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	pw[0] = 1;
	REP(i, 0, n) pw[i + 1] = (pw[i] << 1) % Mod;
	memset(lst, -1, sizeof lst);
	int cur = 0;
	int ans = 1;
	int cnt = 0;
	REP(i, 0, n) if (!~lst[i])
	{
		int u = i;
		while (1)
		{
			lst[u] = cur++;
			u = a[u];
			if (~lst[u])
			{
				if (lst[u] >= lst[i])
				{
					cnt += cur - lst[u];
					ans = (LL)ans * (pw[cur - lst[u]] - 2) % Mod;
				}
				break;
			}
		}
	}
	ans = (LL)ans * pw[n - cnt] % Mod;
	printf("%d\n", ans);
	return 0;
}