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
const int N = 1e5 + 10;
int a[N], lx[N], rx[N];
int main()
{
	int n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 2, n)
	{
        if (a[i] > a[i - 1]) lx[i] = lx[i - 1] + 1;
        else lx[i] = 0;
    }
    rrep(i, n - 1, 1)
    {
        if (a[i] > a[i + 1]) rx[i] = rx[i + 1] + 1;
        else rx[i] = 0;
    }

    int mxl = 0, k = 0, id = 0;

    rep(i, 1, n) mxl = max(mxl, max(rx[i], lx[i]));
    rep(i, 1, n)
		if (mxl == lx[i] || mxl == rx[i])
			k ++, id = i;
    if (lx[id] % 2 == 0 && lx[id] == rx[id] && k <= 1) printf("1\n");
    else printf("0\n");
}