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

int cnt[1024];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, K, x;
	scanf("%d%d%d", &n, &K, &x);
	REP(i, 0, n)
	{
		int tmp;
		scanf("%d", &tmp);
		++cnt[tmp];
	}
	REP(i, 0, K)
	{
		int now = 0;
		static int nxt[1024];
		memset(nxt, 0, sizeof nxt);
		REP(j, 0, 1024)
		{
			int num = (cnt[j] + !now) >> 1;
			nxt[j ^ x] += num;
			nxt[j] += cnt[j] - num;
			now ^= cnt[j] & 1;
		}
		memcpy(cnt, nxt, sizeof cnt);
	}
	int Min = 1024, Max = 0;
	REP(i, 0, 1024) if (cnt[i]) chkmin(Min, i), chkmax(Max, i);
	printf("%d %d\n", Max, Min);
	return 0;
}