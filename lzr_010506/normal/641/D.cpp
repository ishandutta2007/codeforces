#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e6 + 10;

double a[N], b[N], c[N], d[N];

int main()
{
    int n;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%lf", &a[i]);
    rep(i, 1, n) scanf("%lf", &b[i]);
    rep(i, 2, n) a[i] = a[i - 1] + a[i];
    rrep(i, n - 1, 1) b[i] = b[i + 1] + b[i];
    rep(i, 1, n)
    {
        double B = -(1 + a[i] - b[i + 1]);
        double C = a[i];
        double delta = max(B * B - 4.0 * C, 0.0);
        c[i] = (-B + sqrt(delta)) / 2.0;
        d[i] = (-B - sqrt(delta)) / 2.0;
    }
    rep(i, 1, n)
        printf("%.6f ",c[i] - c[i - 1]);
  	puts("");
  	rep(i, 1, n)
  		printf("%.6f ",d[i] - d[i - 1]);
  	return 0;
}