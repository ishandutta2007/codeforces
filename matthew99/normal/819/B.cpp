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

const int maxn = 1000100;

int n;
int a[maxn + 5];

vector<int> all[maxn + 5];

bool now[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	int delta = 0;
	LL sum = 0;
	REP(i, 0, n)
	{
		sum += abs(a[i] - i);
		if (a[i] > i) 
		{
			now[i] = 1;
			all[a[i] - i - 1].pb(i);
			--delta;
		}
		else now[i] = 0, all[a[i] - i + n - 1].pb(i), ++delta;
	}
	LL cur = sum;
	LL ans = cur;
	int ansp = 0;
	REP(i, 0, n)
	{
		cur += delta;
		cur += (a[n - i - 1] << 1) - n;
		if (chkmin(ans, cur)) ansp = i + 1;
		if (now[n - i - 1])
		{
			delta += 2;
		}
		else
		{
			delta -= 2;
		}
		now[n - i - 1] = !now[n - i - 1];

		for (auto u : all[i])
		{
			if (now[u])
			{
				delta += 2;
			}
			else
			{
				delta -= 2;
			}
			now[u] = !now[u];
		}
	}
	cout << ans << ' ' << ansp << endl;
	return 0;
}