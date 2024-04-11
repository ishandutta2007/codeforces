#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;

inline ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

ll n, m, a, d, ans;
int main()
{
	n = read();
	m = read();
	a = read();
	d = read();
	ll T = 0, t = d / a + 1, e = 0, x;
	rep(i, 1, m)
	{
		x = read();
		if (T < n)
		{
			int D = min((x - 1) / a, n);
			if (D > T)
			{
				ans += (D - T - 1) / t + 1;
				T += ((D - T - 1) / t + 1) * t;
				e = min((T - t + 1), n) * a + d;
				T = min(T, n);
			}
		}
		if (e < x)
		{
			ans ++;
			e = x + d;
			T = min(e / a, n);
		}
	}
	if (T < n) ans += (n - T - 1) / t + 1;
	cout << ans << endl;
	return 0;
}