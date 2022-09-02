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

const int maxabs = 2.1e6;
const int maxn = 200100;

int n;
int a[maxn + 5];

int cnta[maxabs + 5];
int cntp[maxabs + 5];

int f[maxabs + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(f, -1, sizeof f);
	for (int i = 2; i <= maxabs; ++i) for (int j = i; j <= maxabs; j += i)
		if (!~f[j]) f[j] = i;
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), ++cnta[a[i]];
	bool flag = 0;
	REP(i, 2, maxabs + 1) if (cnta[i] > 1)
	{
		if (cnta[i] > 2) flag = 1;
		chkmax(cntp[i], 1);
		bool improved = 0;
		int j = i - 1;
		while (j > 1)
		{
			int cnt = 0;
			int now = f[j];
			while (f[j] == now)
			{
				++cnt;
				j /= f[j];
			}
			if (chkmax(cntp[now], cnt)) improved = 1;
		}
		if (!improved) flag = 1;
	}
	for (int i = maxabs; i >= 2; --i) if (cnta[i] == 1)
	{
		if (!cntp[i]) cntp[i] = 1;
		else
		{	
			bool improved = 0;
			int j = i - 1;
			while (j > 1)
			{
				int cnt = 0;
				int now = f[j];
				while (f[j] == now)
				{
					++cnt;
					j /= f[j];
				}
				if (chkmax(cntp[now], cnt)) improved = 1;
			}
			if (!improved) flag = 1;
		}
	}
	int ans = 1;
	REP(i, 2, maxabs + 1)
	{
		REP(j, 0, cntp[i]) ans = (LL)ans * i % Mod;
	}
	if (flag) (++ans) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}