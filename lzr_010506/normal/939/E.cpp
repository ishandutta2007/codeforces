#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
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
const int N = 1e6  + 10;
ll a[N], sz, sum, pos;
int main() 
{
	int n = read();
	rep(i, 1, n)
	{
		int op, val;
		op = read();
		if (op == 2) printf("%.10lf\n", a[sz] - 1.0 * (a[sz] + sum) / (pos + 1));
		else 
		{
			val = read();
			a[++ sz] = val;
			while (pos + 1 < sz) 
			{
				if (1.0 * (a[sz] + sum) / (pos + 1) >= 1.0 * (a[sz] + sum + a[pos + 1]) / (pos + 2)) sum += a[++ pos];
				else goto L1;
			}
			L1:;
		}
	}
	return 0;
}