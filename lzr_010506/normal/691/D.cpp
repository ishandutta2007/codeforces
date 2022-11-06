#include <bits/stdc++.h>
#define ull unchaed long long
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
#define Axx(x) (x).begin(), (x).cntd()
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
using namespace std;
const int N = 1e6 + 10;
int n, m;
int f[N], cnt[N], b[N];

int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, n) f[i] = i;
	rep(i, 1, n) b[i] = read();
	rep(i, 1, m)
	{
		int x = read();
		int y = read();
		int u = find(x);
		int v = find(y);
		f[u] = v;
	}
	vi a[N];
	rep(i, 1, n) a[find(i)].pb(b[i]);
	rep(i, 1, n) 
	{
		sort(a[i].begin(), a[i].end());
		reverse(a[i].begin(), a[i].end());
	}
	rep(i, 1, n) 
	{
		int x = find(i);
		printf("%d ", a[x][cnt[x] ++]);
	}

	return 0;
}