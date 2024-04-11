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
const ll mod = 998244353;
const int N = 5e5 + 10;
int l[N], r[N], mx[N], num[N];
int n, a[N], f[N];

int main() 
{
	n = read();
	rep(i, 1, n) a[i] = read();

	rrep(i, n, 1)
	{
        if (!r[a[i]]) r[a[i]] = i;
        l[a[i]] = i;
        mx[i] = max(mx[i - 1], ++ num[a[i]]);
    }
    rep(i, 1, n)
    {
        f[i] = f[i - 1];
        if (i == r[a[i]]) f[i] = max(f[i], f[l[a[i]] - 1] + num[a[i]]);
    }
    int ans = 0;
    rep0(i, n + 1) ans = max(ans, f[i] + mx[i + 1]);
    printf("%d\n", n - ans);
    return 0;
}