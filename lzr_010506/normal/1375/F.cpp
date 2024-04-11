#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1z
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
ll a[3];
int main()
{
	rep0(i, 3) a[i] = read();
	puts("First");
	fflush(stdout);
	printf("10000000000\n");
	fflush(stdout);
	int x = read();
	if(x == 0) return 0;
	a[x - 1] += 10000000000LL;
	if(a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) return 0;
	ll mx = *max_element(a, a + 3);
	ll rest = mx * 3 - a[0] - a[1] - a[2];
    printf("%lld\n", rest);
    fflush(stdout);
    if(a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) return 0;
    x = read();
    if(x == 0) return 0;
    a[x - 1] += rest;
    mx = *max_element(a, a + 3);
	ll mn = *min_element(a, a + 3);
	printf("%lld\n", (mx - mn) / 2);
	fflush(stdout);
	return 0;
}