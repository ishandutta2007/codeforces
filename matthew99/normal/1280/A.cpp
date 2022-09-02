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

const int Mod = 1e9 + 7;

const int maxn = 1000100;

int n;

int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		static char s[maxn + 5];
		int lim;
		scanf("%d", &lim);
		scanf("%s", s);
		n = strlen(s);
		REP(i, 0, n) a[i] = s[i] - '0';
		int cur = n;
		REP(i, 0, lim)
		{
			int period = (cur - i - 1);
			REP(j, 0, period * (a[i] - 1))
				if (cur < lim) 
				{
					a[cur] = a[cur - period];
					++cur;
				}
				else break;
			n = (n + LL(n - i - 1) * (a[i] - 1)) % Mod;
		}
		(n += Mod) %= Mod;
		printf("%d\n", n);
	}
	return 0;
}