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

const int maxn = 100010;

LL f[2][555];

inline int get(int a, int x, int y, int move)
{
	int d[3], c[3];
	REP(i, 0, 3) d[i] = a & 3, a >>= 2;
	REP(i, 0, 3) c[i] = a & 1, a >>= 1;
	if (y < 0)
	{
		REP(i, 0, 2) if (d[i] == 1 || d[i] == 2) return 0;
		if (d[2] != 2) return 0;
		REP(i, 0, 2) if (d[i] && c[i] != c[2]) return 0;
		return 1;
	}
	--move;
	if (~move && (move & 1))
	{
		if (!d[y]) return -1;
		++d[y];
		if (x == 1 && !y)
		{
			if (d[y] != 2) return -1;
		}
		else if (d[y] != 3) return -1;
		d[y] = 2;
	}
	else 
	{
		if (x == 1 && !y)
		{
			if (d[y] != 2) return -1;
		}
		else if (d[y] && d[y] != 3) return -1;
		if (d[y])
		{
			bool find = 0;
			REP(i, 0, 3) if (i != y && c[i] == c[y]) { find = 1; break; }
			if (!find) return -1;
		}
		if (~move) d[y] = 1, c[y] = 2;
		else d[y] = 0, c[y] = 0;
	}
	if (~move && (move >> 1 & 1))
	{
		if (!y) return -1;
		++d[y - 1];
		++d[y];
		int from = c[y - 1], to = c[y];
		REP(i, 0, 3) if (d[i] && c[i] == from) c[i] = to;
	}
	REP(i, 0, 3) if (d[i] > 3) return -1;
	int val[3];
	int num = 0;
	memset(val, -1, sizeof val);
	REP(i, 0, 3) if (d[i])
	{
		if (!~val[c[i]]) val[c[i]] = num++;
		c[i] = val[c[i]];
	}
	if (num > 2) return -1;
	int ret = 0;
	for (int i = 2; i >= 0; --i) (ret <<= 1) |= c[i];
	for (int i = 2; i >= 0; --i) (ret <<= 2) |= d[i];
	return ret;
}

int n;
int a[maxn + 5][3];

LL ans = 0;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, 3) REP(j, 0, n) scanf("%d", a[j] + i);
	if (n == 1)
	{
		ans = 0;
		REP(i, 0, 3) ans += a[0][i];
		cout << ans << endl;
	}
	else
	{
		memset(f, -oo, sizeof f);
		LL ninf = f[0][0];
		f[0][0] = 0;
		int cur = 0;
		REP(i, 0, n)
		{
			REP(j, 0, 3)
			{
				memset(f[!cur], -oo, sizeof f[!cur]);
				REP(k, 0, 512) if (f[cur][k] > ninf)
				{
					REP(move, 0, 5)
					{
						int tmp = get(k, i, j, move); 
						if (~tmp) chkmax(f[!cur][tmp], f[cur][k] + (move ? a[i][j] : 0));
					}
				}
				cur = !cur;
			}
		}
		ans = LLONG_MIN;
		REP(i, 0, 512) if (f[cur][i] > ninf && get(i, n, -1, -1)) chkmax(ans, f[cur][i]);
		cout << ans << endl;
	}
	return 0;
}