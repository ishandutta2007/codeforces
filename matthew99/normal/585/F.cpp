#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int Mod = 1e9 + 7;

const int maxn = 1000, maxm = 50;

int n, d;

int s[maxn + 5], sx[maxm + 5], sy[maxm + 5];

int go[maxn * maxm + 5][10], nxt[maxn * maxm + 5], fa[maxn * maxm + 5], val[maxn * maxm + 5], dep[maxn * maxm + 5];

int rt = -1;
int trie_tot = 0;

inline void add_mod(int &rt, int *s, const int &res)
{
	if (rt == -1) rt = trie_tot++;
	if (res == 0) return;
	add_mod(go[rt][s[0]], s + 1, res - 1);
	val[go[rt][s[0]]] = s[0];
	fa[go[rt][s[0]]] = rt;
}

inline int &add_mod(int &x, const int &y, const int &z) { return (x += y) %= z; }

int calc(int *l, const int &ty)
{
	static int dp[2][maxn * maxm + 5][2][2];
	memset(dp, 0, sizeof dp);
	dp[0][0][1][0] = 1;
	REP(i, 0, d)
	{
		int cur = i & 1, nxt = !cur;
		memset(dp[nxt], 0, sizeof dp[nxt]);
		REP(a, 0, trie_tot) REP(b, 0, 2) REP(c, 0, 2)
			if (dp[cur][a][b][c])
				REP(j, 0, (b == 1 ? l[i] + 1 : 10))
				{
					int lyc = go[a][j];
					add_mod(dp[nxt][lyc][b & (j == l[i])][c | (dep[lyc] >= (d >> 1))], dp[cur][a][b][c], Mod);
				}
	}
	int lst = d & 1;
	int ret = 0;
	REP(a, 0, trie_tot) REP(b, 0, ty + 1) add_mod(ret, dp[lst][a][b][1], Mod); 
	return ret;
}

inline void init()
{
	static char ss[maxn + 5];
	scanf("%s", ss);
	n = strlen(ss);
	REP(i, 0, n) s[i] = ss[i] - '0';
	scanf("%s", ss);
	d = strlen(ss);
	REP(i, 0, d) sx[i] = ss[i] - '0';
	scanf("%s", ss);
	REP(i, 0, d) sy[i] = ss[i] - '0';
}

inline void prepare()
{
	memset(go, -1, sizeof go);
	trie_tot = 0, rt = -1;
	REP(i, 0, n) add_mod(rt, s + i, min(d, n - i));
	dep[rt] = 0;
	REP(i, 1, trie_tot) dep[i] = dep[fa[i]] + 1;
	static int q[maxn * maxm + 5];
	int head = 0, rear = 0;
	q[rear++] = rt;
	while (head != rear)
	{
		int x = q[head++];
		if (x != rt && fa[x] != rt) nxt[x] = go[nxt[fa[x]]][val[x]];
		else nxt[x] = rt;
		REP(i, 0, 10)
			if (go[x][i] == -1) 
			{
				if (x == rt) go[x][i] = x;
				else go[x][i] = go[nxt[x]][i];
			}
			else q[rear++] = go[x][i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	prepare();
	int ans = (calc(sy, 1) - calc(sx, 0)) % Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}