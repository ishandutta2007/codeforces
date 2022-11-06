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
const int N = 1e6 + 10;
int n,m,a[2005],b[2005],c[2005],d[2005],f[1000005],ans;
void u(int &x,int y){if(y>x)x=y;}
int main()
{
	n = read();
	m = read();
	rep(i, 1, n) a[i] = read(), b[i] = read();
	rep(i, 1, m) c[i] = read(), d[i] = read();
	rep(i, 1, n)
		rep(j, 1, m)
			if(a[i] <= c[j] && b[i] <= d[j])
				f[c[j] - a[i]] = max(f[c[j] - a[i]], d[j] - b[i] + 1);
	rrep(i, 1000000, 1) f[i - 1] = max(f[i - 1], f[i]);
	ans = 0x7f7f7f7f;
	rep0(i, 1000001) ans = min(ans, f[i] + i);
	printf("%d\n", ans);
    return 0;
}