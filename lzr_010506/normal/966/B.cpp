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
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ite iterator
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
using namespace std;
const int N = 300010;
int n, x1, x2;
int c[N], bc[N];
pii p[N];
ll suf[N];

int Div(int a, int b)
{
    int ret = a / b;
    if (a % b) ++ ret;
    return ret;
}

int main()
{
	n = read();
	x1 = read();
	x2 = read();
	rep(i, 1, n)
	{
		c[i] = read();
		p[i] = mp(c[i], i);
	}
    sort(p + 1, p + n + 1);
    sort(c + 1, c + n + 1);
    ll tot = 0;
    rrep(i, n, 1)
    {
        ++ tot;
        if (c[i] * tot > suf[i + 1]) suf[i] = c[i] * tot, bc[i] = i;
        else suf[i] = suf[i + 1], bc[i] = bc[i + 1];
    }
    rep(i, 1, n)
    {

        int x = Div(x1, c[i]);
        if (i + x <= n)
            if (suf[i + x] >= x2)
            {
                puts("Yes");
                int k = bc[i + x];
                int k1 = x, k2 = Div(x2, c[k]);
                printf("%d %d\n", k1, k2);
                rep0(j, k1) printf("%d ", p[i + j].Y);
	            puts("");
	            rep0(j, k2) printf("%d ", p[k + j].Y);
                return 0;
            }



        x = Div(x2, c[i]);
        if (i + x <= n)
            if (suf[i + x] >= x1)
            {
                puts("Yes");
                int k = bc[i + x];
                int k2 = x, k1 = Div(x1, c[k]);
                printf("%d %d\n", k1, k2);
                rep0(j, k1) printf("%d ", p[k + j].Y);
	            puts("");
	            rep0(j, k2) printf("%d ", p[i + j].Y);
                return 0;
            }

    }
    puts("No");
    return 0;
}