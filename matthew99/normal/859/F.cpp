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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200100;

int n;
LL C;
int one[maxn + 5];
int two[maxn + 5];

LL pre_one[maxn + 5], pre_two[maxn + 5];

LL Max = LLONG_MIN;
LL dp[maxn + 5];

deque<int> q;

int ptr = 0;

inline void add(int x)
{
	while (!q.empty() && dp[q.back()] - pre_one[q.back()] - pre_two[q.back()] <= dp[x] - pre_one[x] - pre_two[x]) q.pop_back();
	q.pb(x);
}

inline void get(int x)
{
	chkmax(dp[x], Max + C);
	while (!q.empty() && q.front() < ptr) q.pop_front();
	if (!q.empty()) chkmax(dp[x], dp[q.front()] + pre_one[x] - pre_one[q.front()] + pre_two[x - 1] - pre_two[q.front()]);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%" LLFORMAT "d", &n, &C);
	REP(i, 0, n)
	{
		scanf("%d", one + i);
		if (i + 1 < n) scanf("%d", two + i);
	}
	memset(dp, 0, sizeof dp);
	pre_one[0] = pre_two[0] = 0;
	REP(i, 0, n) pre_one[i + 1] = pre_one[i] + one[i];
	REP(i, 0, n - 1) pre_two[i + 1] = pre_two[i] + two[i];
	dp[0] = 0;
	add(0);
	ptr = 0;
	REP(i, 1, n + 1)
	{
		while (ptr < i && pre_one[i] - pre_one[ptr] + pre_two[i - 1] - pre_two[ptr] > C) chkmax(Max, dp[ptr++]);
		get(i);
		if (i < n) add(i);
	}
	printf("%" LLFORMAT "d\n", dp[n]);
	return 0;
}