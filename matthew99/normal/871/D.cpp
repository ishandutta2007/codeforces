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

const int maxn = 10000100;

int n;

int phi[maxn + 5];
bool ispr[maxn + 5];
vector<int> pr;

int min_fac[maxn + 5];

int fen[maxn + 5];

int tot = 0;

inline void prepare()
{
	memset(ispr, 1, sizeof ispr);
	ispr[0] = ispr[1] = 0;
	REP(i, 2, n + 1)
	{
		if (ispr[i]) pr.pb(i), phi[i] = i - 1, min_fac[i] = i;
		for (int j = 0; j < SZ(pr) && i * pr[j] <= n; ++j)
		{
			ispr[i * pr[j]] = 0;
			min_fac[i * pr[j]] = pr[j];
			if (!(i % pr[j]))
			{
				phi[i * pr[j]] = phi[i] * pr[j];
				break;
			}
			else 
			{
				phi[i * pr[j]] = phi[i] * phi[pr[j]];
			}
		}
	}
}

inline void add(int x, int y)
{
	tot += y;
	for (int i = x; i <= n; i += i & -i) fen[i] += y;
}

inline int query(int x)
{
	int ret = 0;
	for (int i = x; i > 0; i -= i & -i) ret += fen[i];
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	prepare();
//i < j
//(i, j) != 1    1
//2min_fac[i] > n    0
//2min_fac[j] > n    0
//min_fac[i] * min_fac[j] <= n 2
//otherwise 3
	LL ans = 0;
	for (int j = 2; j <= n; ++j)
	{
		if (2 * min_fac[j] <= n)
		{
			ans += tot * 3;
			ans -= query(n / min_fac[j]);
			ans -= j - 1 - phi[j];
			add(min_fac[j], 1);
		}
	}
	cout << ans << endl;
	return 0;
}