#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
int n, dep[100010];
vector<int> a[100010], pt;
db ans = 0;

void dfs(int u, int p, int d, db prob)
{
    int ct = 0;
    for (int v : a[u]) if (v != p) ct ++;
    for (int v : a[u]) if (v != p) dfs(v, u, d + 1, prob / ct);
    if (ct == 0) ans += prob * d;
}

int main()
{
	n = read();
	rep(i, 1, n - 1)
	{
		int x, y;
		x = read();
		y = read();
		x --;
		y --;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(0, -1, 0, 1.0);
	printf("%.10lf", ans);
	return 0;
}