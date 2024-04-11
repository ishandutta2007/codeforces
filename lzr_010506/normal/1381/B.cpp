#include <bits/stdc++.h>
#define pcc pair<char, char>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define eps 1e-9
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e6 + 10;

int n, a[N];
bitset<8111> x, y;
int main()
{
	int T = read();
	while(T --)
	{
		n = read();
		rep(i, 1, 2 * n) a[i] = read();
		vi len;
		int cur = 1;
		while(cur <= (n << 1))
		{
			int nxt = cur;
			while(nxt <= (n << 1) && a[nxt] <= a[cur]) nxt ++;
			len.pb(nxt - cur);
			cur = nxt;
		}
		x.reset();
		y.reset();
		x.set(4000);
		for(auto v : len)
		{
			y = (x << v) | (x >> v);
			x = y;
		}
		if(x.test(4000)) puts("YES");
		else puts("NO");
	}
	return 0;
}