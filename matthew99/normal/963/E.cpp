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

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxR = 60, maxv = 300;

const int walk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int R, a[4];

int tot = 1;
map<pair<int, int>, int> id;

bool g[(maxR << 1) + 5][(maxR << 1) + 5];
int f[(maxR << 1) + 5][(maxR << 1) + 5][maxv + 5];

bool in[(maxR << 1) + 5][(maxR << 1) + 5];

void dfs(int x, int y)
{
	if (x * x + y * y > R * R) return;
	if (g[x + maxR][y + maxR]) return;
	g[x + maxR][y + maxR] = 1;
	int u = -1, v = -1;
	bool flag = 0;
	REP(i, 0, 4)
	{
		u = x + walk[i][0], v = y + walk[i][1];
		if (u * u + v * v > R * R) continue;
		if (in[u + maxR][v + maxR]) continue;
		if (abs(u) + abs(v) > abs(x) + abs(y)) 
		{
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		f[x + maxR][y + maxR][tot] = 1;
		++tot;
		return;
	}
	in[u + maxR][v + maxR] = 1;
	dfs(u, v);
	int coe[maxv + 5] = {0};
	memcpy(coe, f[u + maxR][v + maxR], sizeof coe);
	(--coe[0]) %= Mod;
	int tmp = 0;
	REP(i, 0, 4)
	{
		int xx = u + walk[i][0], yy = v + walk[i][1];
		if (xx == x && yy == y) tmp = fpm(a[i], Mod - 2, Mod);
		else
		{
			dfs(xx, yy);
			REP(j, 0, tot) (coe[j] -= (LL)f[xx + maxR][yy + maxR][j] * a[i] % Mod) %= Mod;
		}
	}
	REP(i, 0, tot) coe[i] = (LL)coe[i] * tmp % Mod;
	memcpy(f[x + maxR][y + maxR], coe, sizeof f[x + maxR][y + maxR]);
}

const int maxn = 10010;

int eqn = 0;
int eq[maxn + 5][maxv + 5];

int ans;

int v[maxv + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &R);
	REP(i, 0, 4) scanf("%d", a + i);
	int tmp = fpm(a[0] + a[1] + a[2] + a[3], Mod - 2, Mod);
	REP(i, 0, 4) a[i] = (LL)a[i] * tmp % Mod;
	memset(f, 0, sizeof f);
	memset(g, 0, sizeof g);
	REP(i, -R, R + 1) REP(j, -R, R + 1)
		if (i * i + j * j <= R * R)
		{
			dfs(i, j);
		}
	eqn = 1;
	REP(i, -R, R + 1) REP(j, -R, R + 1)
		if (i * i + j * j <= R * R && !in[i + maxR][j + maxR])
		{
			memcpy(eq[eqn], f[i + maxR][j + maxR], sizeof eq[eqn]);
			(--eq[eqn][0]) %= Mod;
			REP(k, 0, 4)
			{
				int x = i + walk[k][0], y = j + walk[k][1];
				REP(l, 0, tot) (eq[eqn][l] -= (LL)a[k] * f[x + maxR][y + maxR][l] % Mod) %= Mod;
			}
			++eqn;
		}
	REP(i, 1, tot)
	{
		REP(j, i, eqn)
		{
			if (eq[j][i])
			{
				REP(k, 0, tot) swap(eq[j][k], eq[i][k]);
				break;
			}
		}
		int inv = fpm(eq[i][i], Mod - 2, Mod);
		REP(j, 1, eqn) if (j != i && eq[j][i])
		{
			int c = (LL)eq[j][i] * inv % Mod;
			REP(k, 0, tot) (eq[j][k] -= (LL)eq[i][k] * c % Mod) %= Mod;
		}
	}
	REP(i, 1, tot) v[i] = (LL)-eq[i][0] * fpm(eq[i][i], Mod - 2, Mod) % Mod;
	ans = f[maxR][maxR][0];
	REP(i, 1, tot) (ans += (LL)f[maxR][maxR][i] * v[i] % Mod) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}