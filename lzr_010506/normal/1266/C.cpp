#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
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
int a[510][510];
 
int main()
{
	int r = read();
	int c = read();
	if(r == 1 && c == 1) {puts("0"); return 0;}
	if(r == 1)
	{
		rep(i, 2, c + 1) printf("%d ", i);
		return 0;
	}
	if(c == 1)
	{
		rep(i, 2, r + 1) printf("%d\n", i);
		return 0;
	}
	rep(i, 1, c) a[1][i] = i + 1;
	rep(i, 2, r)
		rep(j, 1, c)
			a[i][j] = 1;
	rep(i, 2, r)
		rep(j, 1, c)
			a[i][j] = a[1][j] * (c + i) * (j + 1);
	rep(i, 1, r)
	{
		rep(j, 1, c)
			printf("%d ", a[i][j]);
		puts("");
	}
 
	return 0;
}