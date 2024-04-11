#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define pi complex<ld>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
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
const int N = 200010;
const int P = 1e9 + 7;

int dp[110][110][110];
int pw[110];
int Add(int a, int b)
{
	a += b;
	return a >= P ? a - P : a;
}

char ch[110];

int main()
{
	int n, x;
	n = read();
	x = read();
	scanf("%s", ch + 1);
	rep(i, 1, n)
		dp[ch[i] - '0'][i][i] = 1;
	pw[0] = pw[1] = 2;

	rep(i, 2, x)
	{
		pw[i] = (ll)(pw[i - 1]) * pw[i - 2] % P;
		rep(l, 1, n)
			rep(r, l, n)
			{
				dp[i][l][r] = Add((ll)(dp[i - 1][l][r]) * (r == n ? pw[i - 2] : 1) % P, (ll)(dp[i - 2][l][r]) * (l == 1 ? pw[i - 1] : 1) % P);
				rep(m, l, r - 1)
					dp[i][l][r] = Add(dp[i][l][r], (ll)(dp[i - 1][l][m]) * dp[i - 2][m + 1][r] % P);
			}
	}
	cout << dp[x][1][n] << endl;
	return 0;
}