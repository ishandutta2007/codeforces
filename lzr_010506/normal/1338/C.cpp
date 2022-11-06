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
#define dep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 1e6 + 10;
ll num[] = {2ll, 3, 8ll, 12ll, 32ll, 48ll, 128ll, 192ll, 512ll, 768ll, 2048ll, 3072ll, 8192ll, 12288ll, 32768ll, 49152ll, 131072ll, 196608ll, 524288ll, 786432ll, 2097152ll, 3145728ll, 8388608ll, 12582912ll, 33554432ll, 50331648ll, 134217728ll, 201326592ll, 536870912ll, 805306368ll, 2147483648ll, 3221225472ll, 8589934592ll, 12884901888ll, 34359738368ll, 51539607552ll, 137438953472ll, 206158430208ll, 549755813888ll, 824633720832ll, 2199023255552ll, 3298534883328ll, 8796093022208ll, 13194139533312ll, 35184372088832ll, 52776558133248ll, 140737488355328ll, 211106232532992ll, 562949953421312ll, 844424930131968ll, 2251799813685248ll, 3377699720527872ll, 9007199254740992ll, 13510798882111488ll, 36028797018963968ll, 54043195528445952ll, 144115188075855872ll, 216172782113783808ll, 576460752303423488ll, 864691128455135232ll, 2305843009213693952ll, 3458764513820540928};
ll wei(ll y)
{
	ll ret = 0;
	rep0(i, 60) if ((y >> i) & 1) ret ^= num[i];
	return ret;
}
int main()
{
	int T = read();
	while (T --)
	{
		ll n = read1();
		if (n <= 3)
		{
			printf("%lld\n", n);
			continue;
		}
		int m = 0;
		while (1ll << (m + m) <= n) m ++;
		m --;
		ll base = 1ll << (m + m);
		ll pos = (n - 1) / 3 + 1;
		ll H = n - pos * 3 + 3;
		//cout << H << endl;
		n = (n - base) / 3;
		if (H == 2) cout << base + base + wei(n) << endl;
		if (H == 3) cout << ((base + n) ^ (base + base + wei(n))) << endl;
		if (H == 1) cout << base + n << endl;
	}
	return 0;
}