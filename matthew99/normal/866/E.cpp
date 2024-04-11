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

const int maxn = 14;

int n;
int a[maxn + 5];

map<LL, LL> dp;

int get(char x)
{
	if (x >= 'a') return x - 'a' + 10;
	return x - '0';
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char s[maxn + 5];
	scanf("%s", s), n = strlen(s);
	reverse(s, s + n);
	REP(i, 0, n) a[i] = get(s[i]);
	dp[0] = 0;
	LL ans = LLONG_MAX;
	for (auto u : dp)
	{
		LL mask = u.x;
		int now = mask & 15; mask >>= 4;
		static int carry[maxn + 5], filled[maxn + 5];
		static int tmp_carry[maxn + 5], tmp_filled[maxn + 5];
		REP(i, 0, n) carry[i] = mask & 1, mask >>= 1;
		bool empty = !mask;
		if (mask == (1 << n) - 1 && !now)
		{
			chkmin(ans, u.y);
			continue;
		}
		REP(i, 0, n) filled[i] = mask & 1, mask >>= 1;
		REP(i, 0, n)
			if (!filled[i])
			{
				if (empty && i < n - 1) continue;
				int fromj = carry[i], toj = carry[i] + 1;
				if (i > 0 && !filled[i - 1]) fromj = 0, toj = 2;
				REP(j, fromj, toj)
				{
					LL tmp_val = u.y;
					tmp_val |= (LL)now << (i * 4);
					memcpy(tmp_carry, carry, sizeof tmp_carry);
					memcpy(tmp_filled, filled, sizeof tmp_filled);
					int tmp_now = now + a[i] + j;
					if (tmp_now >= 16)
					{
						if (i + 1 >= n) continue;
						if (tmp_filled[i + 1])
						{
							if (tmp_carry[i + 1]) tmp_carry[i + 1] = 0;
							else continue;
						}
						else tmp_carry[i + 1] = 1;
						tmp_now -= 16;
					}
					else
					{
						if (i + 1 < n && tmp_filled[i + 1])
						{
							if (tmp_carry[i + 1]) continue;
						}
					}
					tmp_filled[i] = 1;
					if (i > 0 && !tmp_filled[i - 1]) tmp_carry[i] = j;
					else tmp_carry[i] = 0;
					LL new_mask = 0;
					for (int l = n - 1; l >= 0; --l)
						(new_mask <<= 1) |= tmp_filled[l];
					for (int l = n - 1; l >= 0; --l)
						(new_mask <<= 1) |= tmp_carry[l];
					(new_mask <<= 4) |= tmp_now;
					if (!dp.count(new_mask)) dp[new_mask] = tmp_val;
					else chkmin(dp[new_mask], tmp_val);
				}
			}
	}
	if (ans == LLONG_MAX) puts("NO");
	else 
	{
		for (int i = n - 1; i >= 0; --i) printf("%x", (int)(ans >> (i * 4) & 15));
	}
	return 0;
}