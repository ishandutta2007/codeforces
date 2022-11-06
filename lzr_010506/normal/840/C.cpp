#include <bits/stdc++.h>
#include <math.h>
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
#define ept 1e-9

using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 610;
const int mod = 1e9 + 7;
map<int, int> Mp;
int f[N][N], C[N][N];
int n, x, t, k, m, pi = 1;
int main()
{
	n = read();
	rep(i, 1, n)
	{
		x = read();
		for(int k = 2; k * k <= x; k ++)
			while (!(x % (k * k)))
				x /= k * k;
		Mp[x] ++;
	}
	rep(i, 0, n * 2)
	{
        C[i][0] = 1;
		rep(j, 1, i)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	f[0][0] = 1;
	n = m = 0;
	map<int,int>::iterator it;
	for (it = Mp.begin(); it != Mp.end(); it ++)
	{
		t = it -> second;
		rep(i, 1, t) pi = 1LL * pi * i % mod;
		rep(i, 0, m)
			if (f[n][i])
				rep(k, 1, t)
					for(int j = 0; j <= i && j <= k; j ++)
						f[n + 1][i - j + t - k] = (f[n + 1][i - j + t - k] + (ll)f[n][i] * C[t - 1][k - 1] % mod * C[i][j] % mod * C[m + 1 - i][k - j] % mod) % mod;
		n ++;
		m += t;
	}
	printf("%I64d\n", 1ll * f[n][0] * pi % mod);
	return 0;
}