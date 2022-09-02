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

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	if (n <= 2)
	{
		printf("1\n");
		REP(i, 0, n) printf("1 ");
		printf("\n");
	}
	else
	{
		static bool vis[100005];
		memset(vis, 0, sizeof vis);
		printf("2\n");
		REP(i, 2, n + 2)
		{
			if (!vis[i]) for (int j = i << 1; j <= n + 1; j += i) vis[j] = 1;
			printf("%d ", vis[i] + 1);
		}
	}
	return 0;
}