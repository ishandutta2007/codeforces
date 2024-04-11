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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 510;
const int mod = 1e9 + 7;
using namespace std;

int n, a[N][N], d[N][N], f[N][N];

int main()
{
	n = read();
	rep0(i, n)
		rep0(j, n)
			a[i][j] = read();
	rep0(i, n) d[i][i] = 1, f[i][i] = 1;
	rep(len, 2, n)
		rep0(i, n)
		{
            int j = (i + len - 1) % n;
            for(int k = i; k != j; k = (k + 1) % n)
            {
                if(a[i][j]) d[i][j] = (d[i][j] + 1LL * f[i][k] * f[(k + 1) % n][j]) % mod;
                f[i][j] = (f[i][j] + 1LL * d[i][(k + 1) % n] * f[(k + 1) % n][j]) % mod;
            }
        }
    printf("%d\n",f[0][n - 1]);
    return 0;
}