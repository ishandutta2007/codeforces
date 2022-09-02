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

const int maxabs = 1000100;

int n, x, y;
int num;
LL sum[(maxabs << 1) + 5][2];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &x, &y);
	num = x / y;
	REP(i, 0, n)
	{
		int u;
		scanf("%d", &u);
		++sum[u][0];
		sum[u][1] += u;
	}
	REP(i, 0, maxabs << 1) REP(j, 0, 2) sum[i + 1][j] += sum[i][j];
	LL ans = LLONG_MAX;
	for (int i = 2; i <= maxabs; ++i)
	{
		LL tmp = 0;
		for (int j = 0; j < maxabs; j += i)
		{
			int mid = max(j, j + i - num - 1);
			tmp += LL(sum[mid][0] - sum[j][0]) * x;
			tmp += LL(sum[j + i - 1][0] - sum[mid][0]) * (j + i) * y;
			tmp -= LL(sum[j + i - 1][1] - sum[mid][1]) * y;
		}
		chkmin(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}