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

const int maxbase = 10;

const int maxlen = 110;

int qn;

LL ways[maxbase + 5][maxbase + 5][maxlen + 5];
LL total[maxbase + 5][maxlen + 5][maxbase + 5];

inline void prepare()
{
	REP(i, 2, maxbase + 1)
	{
		total[i][1][1] = i - 1;
		REP(j, 1, maxlen) REP(k, 0, i + 1) if (total[i][j][k])
		{
			if (k) total[i][j + 1][k - 1] += total[i][j][k] * k;
			if (k < i) total[i][j + 1][k + 1] += total[i][j][k] * (i - k);
		}
		REP(j, 0, i + 1)
		{
			static LL dp[maxlen + 5][maxbase + 5];
			memset(dp, 0, sizeof dp);
			dp[0][j] = 1;
			REP(k, 0, maxlen) REP(l, 0, i + 1) if (dp[k][l])
			{
				if (l) dp[k + 1][l - 1] += dp[k][l] * l;
				if (l < i) dp[k + 1][l + 1] += dp[k][l] * (i - l);
			}
			REP(k, 0, maxlen + 1) ways[i][j][k] = dp[k][0];
		}
	}
}

LL work(LL lim, int base)
{
	vector<int> a;
	while (lim) a.pb(lim % base), lim /= base;
	int N = SZ(a);
	int cnt[maxbase + 5] = {0};
	LL ret = 0;
	REP(i, 1, N)
	{
		ret += total[base][i][0];
	}
	for (int i = N - 1; i >= 0; --i)
	{
		REP(j, 0, a[i])
		{
			if (i == N - 1 && !j) continue;
			cnt[j] ^= 1;
			int tmp = 0;
			REP(k, 0, base) tmp += cnt[k];
			ret += ways[base][tmp][i];
			cnt[j] ^= 1;
		}
		cnt[a[i]] ^= 1;
	}
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int b;
		LL l, r;
		scanf("%d%" LLFORMAT "d%" LLFORMAT "d", &b, &l, &r);
		cout << work(r + 1, b) - work(l, b) << endl;
	}
	return 0;
}