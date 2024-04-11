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
#define All(x) (x).begin(), (x).end()
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
const int p = 998244353;
int n, m;
int f[10000100];
int main()
{
	n = read();
	if(n == 1 || n == 2) 
	{
		puts("1");
		return 0;
	} 
	m = 1;
	while((m * 2) <= n + 1) m *= 2;
	n = n - m + 1;
	f[0] = 0;
	rep(i, 1, 3) f[i] = 1 - f[i - 1];
	for(int i = 4; i * 2 < m; i <<= 1)
	{
		rep0(j, i) f[j + i] = f[j];
		int x = 0;
		rep0(j, (i >> 1)) x += f[j];
		if(x & 1) f[i] = 1;
	}
	int cnt = 0;
	rep0(i, m / 2) cnt += f[i];

	if(cnt > n) puts("0");
	else if(cnt == n) puts("1");
	else if(cnt == n - 1) puts("1");
	else puts("0");
	return 0;
}