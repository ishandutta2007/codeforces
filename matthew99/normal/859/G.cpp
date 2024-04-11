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

const int maxn = 100100;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxMod = 1e9;

int Mod, g;

int n;
char s[maxn + 5];

int main()
{
	srand(time(NULL));
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%s", &n, s);
	REP(tt, 0, 100)
	{
		while (1)
		{
			Mod = n * (Rand() % (maxMod / n - 1) + 1) + 1;
			bool failed = 0;
			for (int j = 2; j * j <= Mod; ++j) if (!(Mod % j))
			{
				failed = 1;
				break;
			}
			if (failed) continue;
			int u = Mod - 1;
			vector<int> all;
			for (int j = 2; j * j <= u; ++j)
				if (!(u % j))
				{
					while (!(u % j)) u /= j;
					all.pb((Mod - 1) / j);
				}
			if (u > 1) all.pb((Mod - 1) / u);
			while (1)
			{
				g = Rand() % (Mod - 1) + 1;
				failed = 0;
				for (auto v : all) if (fpm(g, v, Mod) == 1)
				{
					failed = 1;
					break;
				}
				if (!failed) break;
			}
			break;
		}
		int sum = 0;
		int step = fpm(g, (Mod - 1) / n, Mod);
		int now = 1;
		REP(i, 0, n)
		{
			(sum += LL(s[i] - '0') * now % Mod) %= Mod;
			now = (LL)now * step % Mod;
		}
		if (sum)
		{
			puts("NO");
			exit(0);
		}
	}
	puts("YES");
	return 0;
}