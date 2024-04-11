#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
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
int n, q, P, a[100010];

int phi(int n)
{
	int ans = n;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			ans = ans / i * (i - 1);
			while(n % i == 0)
				n /= i;
		}
	}
	return n != 1 ? ans / n * (n - 1): ans;
}

vector<int> ps;

int exp(int a, int n, int P)
{
	int res = 1;
	for(; n; n >>= 1)
	{
		if(n & 1)
			res = min((ll) res * a % P + P, (ll) res * a);
		a = min((ll) a * a % P + P, (ll) a * a);
	}
	return res;
}

int query(int l, int r, int pn)
{
	if(l > r) return 1;
	if(pn == ps.size() - 1) return min(a[r], 2);
	return exp(a[l], query(l + 1, r, pn + 1), ps[pn]);
}

int main()
{
	int i;
	n = read(); P = read();
	for(i = 1; i <= n; i++) a[i] = read();
	while(P > 1)
		ps.pb(P), P = phi(P); ps.pb(1);
	q = read();
	while(q--)
	{
		int l = read(), r = read();
		printf("%d\n", query(l, r, 0) % ps[0]);
	}
	return 0;
}