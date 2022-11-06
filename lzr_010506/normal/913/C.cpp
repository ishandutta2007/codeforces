#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 50;
ll c[N], mc[N], n, L;

int main() 
{
	int n, L;
	n = read();
	L = read();
	rep(i, 0, n - 1)
		c[i] = read();
	rep(i, 0, n - 1)
		c[i + 1] = min(c[i + 1], 2 * c[i]);
	ll ans = (ll) 1e18;	
	ll sum = 0;
	rrep(i, n - 1, 0)
	{
		int now = L / (1 << i);
		sum += (ll) now * c[i];
		L -= now << i;
		ans = min(ans, sum + (L > 0) * c[i]);
	}
	cout << ans << endl;
	return 0;
}