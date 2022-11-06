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
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define Alsls(x) (x).begin(), (x).end()
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
const int N = 5e4 + 10;
int f[N];
bool b[N];
char c[N];
int i,j,m,n,s,fx,fy;
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
 
int main()
{
	n = read();
	m = read();
	rep(i, 1, n)
	{
		gets(c + 1);
		rep(j, 1, m / 4)
			if (c[j] <= 57) c[j] = c[j] - 48;
			else c[j] = c[j] - 55;
		rep(j, 1, m)
			if (f[j]) f[m + j] = m + f[j], f[j] = 0;
			else f[m + j] = 0;
		rep(j, 1, m)
			b[j] = (c[(j - 1) / 4 + 1] >> (3 - (j - 1) % 4)) & 1;
		rep(j, 1, m)
			if (b[j])
				s ++, f[j] = j;
		rep(j, 1, m)
			if (f[j] && f[m + j])
			{
				fx = find(j);
				fy = find(m + j);
				if (fx != fy)
					f[fy] = fx, s --;
			}
		rep(j, 1, m - 1)
			if (f[j] && f[j + 1])
			{
				fx = find(j);
				fy = find(j + 1);
				if (fx != fy)
					f[fy] = fx, s --;
			}
		rep(j, 1, 2 * m)
			if (f[j])
				find(f[j]);
	}
	printf("%d",s);
	return 0;
}