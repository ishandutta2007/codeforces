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

const int maxn = 3010;

int n;
pair<int, int> a[maxn + 5];

struct data
{
	int a, b, c;

	data() { }
	data(int _a, int _b, int _c): a(_a), b(_b), c(_c) { }

	friend bool operator<(const data &x, const data &y)
	{
		if (x.a != y.a) return x.a > y.a;
		if (x.b != y.b) return x.b > y.b;
		return x.c > y.c;
	}

};

data dp[3][maxn + 5];
int pre[3][maxn + 5];

int out[maxn + 5];

data ans;

int ans0, ans1, ans2;

int w[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", &a[i].x), a[i].y = i;
	sort(a, a + n);
	w[0] = a[0].x;
	REP(i, 1, n) w[i] = a[i].x - a[i - 1].x;
	ans = data(-oo, -oo, -oo);
	for (int l = 1; (l << 1) <= n; ++l)
	{
		REP(i, 0, 3) REP(j, 0, n) dp[i][j] = data(-oo, -oo, -oo), pre[i][j] = -1;
		REP(i, 0, n) dp[0][i] = data(0, 0, w[i]);
		REP(i, 1, 3)
		{
			deque<int> q;
			REP(j, 0, n)
			{
				while (!q.empty() && q.front() < j - (l << 1))
					q.pop_front();
				if (j >= l && dp[i - 1][j - l].a >= 0)
				{
					while (!q.empty() && dp[i - 1][j - l] < dp[i - 1][q.back()]) q.pop_back();
					q.push_back(j - l);
				}
				if (!q.empty()) 
				{
					if (chkmin(dp[i][j], dp[i - 1][q.front()])) pre[i][j] = q.front();
				}
				if (dp[i][j].a >= 0)
				{
					if (i == 1) dp[i][j].b = w[j];
					else if (i == 2) dp[i][j].a = w[j];
				}
			}
		}
		REP(i, n - (l << 1), n - l + 1) if (chkmin(ans, dp[2][i]))
		{
			ans2 = i;
			ans1 = pre[2][i];
			ans0 = pre[1][ans1];
		}
	}
	memset(out, -1, sizeof out);
	REP(i, ans2, n) out[a[i].y] = 1;
	REP(i, ans1, ans2) out[a[i].y] = 2;
	REP(i, ans0, ans1) out[a[i].y] = 3;
	REP(i, 0, n) printf("%d ", out[i]);
	printf("\n");
	return 0;
}