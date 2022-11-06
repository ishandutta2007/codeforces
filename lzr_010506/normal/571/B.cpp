#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
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
#define all(x) (x).begin(), (x).end()
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
const int mod = 1e9 + 7;
int n, m;
int a[300010];
ll dp[5010][5010];

int main()
{
	n = read();
	m = read();
	rep(i, 1, n) a[i] = read();
	sort(a + 1, a + n + 1);
	int num1 = n % m;
	int len1 = n / m + 1;
	int num2 = m - num1;
	int len2 = n / m;
	a[0] = a[1];
	rep(i, 0, num1)
		rep(j, 0, num2)
		{
			if(i)
			{
				int k = (i - 1) * len1 + j * len2;
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[k + 1] - a[k]);
			}
			if(j)
			{
				int k = i * len1 + (j - 1) * len2;
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[k + 1] - a[k]);
			}
		}
	printf("%d", a[n] - a[1] - dp[num1][num2]);
	return 0;
}
/*
dp[i][j]ij
dp[i][j]=max(dp[i1][j]+a[k1+1]a[k1],dp[i][j1]+a[k2+1]a[k2])
*/