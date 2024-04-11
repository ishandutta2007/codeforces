#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define Alsls(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 50 + 5;
inline void chk_min(int &a,int b){ if(a>b) a=b;}
const int C = 200 + 5;
const int X = 500 + 5;
int n;
char ch[N];
int f[N][C * 2 + 5][X * 2 + 5][2];
int dfs(int pos, int c, int x, int delta)
{
	if(pos > n) return c? INF: 0;
	if(c < -C || c > C || x < -X || x > X) return INF;
	if(f[pos][c + C][x + X][delta == 1] != -1) return f[pos][c + C][x + X][delta == 1];
	f[pos][c + C][x + X][delta == 1] = INF;
	f[pos][c + C][x + X][delta == 1] = min(f[pos][c + C][x + X][delta == 1], dfs(pos, c, x + delta, delta) + n - pos + 1);
	f[pos][c + C][x + X][delta == 1] = min(f[pos][c + C][x + X][delta == 1], dfs(pos + 1, c * 10 + ch[pos] - x, x, 1));
	f[pos][c + C][x + X][delta == 1] = min(f[pos][c + C][x + X][delta == 1], dfs(pos + 1, c * 10 + ch[pos] - x, x, -1));
	return f[pos][c + C][x + X][delta == 1];
}
 
int main()
{
	scanf("%s", ch + 2);
	n = strlen(ch + 2) + 1;
	rep(i, 2, n) ch[i] -= '0';
	memset(f, -1, sizeof(f));
	printf("%d\n", dfs(1, 0, 0, 1));
	return 0;
}