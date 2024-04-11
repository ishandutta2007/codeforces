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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;

const int maxw = 12;

int w, n, m;
int cnt[(1 << maxw) + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &w, &n, &m);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	REP(i, 0, m)
	{
		static char s[maxw + 5];
		scanf("%s", s);
		reverse(s, s + w);
		static int tmp[(1 << maxw) + 5];
		REP(j, 0, 1 << w) tmp[j] = cnt[j];
		REP(j, 0, w)
		{
			if (s[j] == 'A' || s[j] == 'a')
			{
				REP(k, 0, 1 << w) if (!(k >> j & 1))
					tmp[k] += tmp[k | (1 << j)];
			}
			else if (s[j] == 'O' || s[j] == 'o')
			{
				REP(k, 0, 1 << w) if (!(k >> j & 1))
					tmp[k | (1 << j)] += tmp[k];
			}
			else if (s[j] == 'X' || s[j] == 'x')
			{
				REP(k, 0, 1 << w) if (!(k >> j & 1))
				{
					tmp[k] += tmp[k | (1 << j)];
					tmp[k | (1 << j)] = tmp[k] - (tmp[k | (1 << j)] << 1);
				}
			}
		}
		REP(j, 0, 1 << w) tmp[j] *= tmp[j];
		int goal = 0;
		REP(j, 0, w)
		{
			if (islower(s[j])) goal |= 1 << j;
			if (s[j] == 'A' || s[j] == 'a')
			{
				REP(k, 0, 1 << w) if (!(k >> j & 1))
					tmp[k] -= tmp[k | (1 << j)];
			}
			else if (s[j] == 'O' || s[j] == 'o')
			{
				REP(k, 0, 1 << w) if (!(k >> j & 1))
					tmp[k | (1 << j)] -= tmp[k];
			}
			else if (s[j] == 'X' || s[j] == 'x')
			{
				REP(k, 0, 1 << w) if (!(k >> j & 1))
				{
					tmp[k | (1 << j)] = (tmp[k] - tmp[k | (1 << j)]) >> 1;
					tmp[k] -= tmp[k | (1 << j)];
				}
			}
		}
		printf("%d\n", tmp[goal]);
	}
	return 0;
}