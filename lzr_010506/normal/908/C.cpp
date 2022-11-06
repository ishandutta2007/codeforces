#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll unsigned long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1010;
double x[N], y[N], r;
int n;


int main()
{
    scanf("%d%lf", &n, &r);
    rep(i, 1, n)
    {
        scanf("%lf", &x[i]);
        y[i] = r;
        rep(j, 1, i - 1) y[i] = max(y[i], sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])) + y[j]);
        printf("%.10lf ", y[i]);
    }
    return 0;
}