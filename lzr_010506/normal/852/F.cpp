#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
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
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 1100000;
int n, m, a, Q, P;
int ans[N], jc[N], ny[N];

int c(int n,int k)
{
	return 1ll * jc[n] * ny[k] % P * ny[n - k] % P;
}

int qpow(int x, int times, int mod)
{
	int now = 1;
	while(times)
	{
		if(times & 1) now = (ll)now * x % mod;
		x = (ll)x * x % mod;
		times >>= 1;
	}
	return now;
}

int main()
{
	n = read();
	m = read();
	a = read();
	Q = read();
	int now = 1;
	for(int i = 1; ; i ++)
	{
		now = 1LL * now * a % Q;
		if(now == 1)
		{
			P = i;
			break;
		}
	}
	jc[0] = 1;
	rep(i, 1, m) jc[i] = 1LL * jc[i - 1] * i % P;
	ny[m] = qpow(jc[m], P - 2, P);
	rrep(i, m - 1, 0) ny[i] = 1ll * ny[i + 1] * (i + 1) % P;
	rep(i, 1, min(n, m + 1)) ans[n - i + 1] = (ans[n - i + 2] + c(m, i - 1)) % P;
	rrep(i, n - min(n, m + 1), 1)ans[i] = ans[i + 1];
	rep(i, 1, n) printf("%d ", qpow(a, ans[i] ,Q));
	return 0;
}