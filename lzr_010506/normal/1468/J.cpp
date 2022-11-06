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

const int N = 2e5 + 10;

struct Edge
{
	int x, y, w;
}e[N];

int f[N];
int n, m, k;

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void mian()
{
	n = read();
	m = read();
	k = read();
	rep(i, 1, n) f[i] = i;
	rep(i, 1, m)
	{
		e[i].x = read();
		e[i].y = read();
		e[i].w = read();
 	}
 	sort(e + 1, e + m + 1, cmp);
 	int mxv = 0, cnt = 0, pos = m + 1;
 	rep(i, 1, m)
 	{
 		if(e[i].w > k) {pos = i; break;}
 		int u = find(e[i].x);
 		int v = find(e[i].y);
 		mxv = e[i].w;
 		//cout << mxv << endl;
 		if(u == v) continue;
 		f[u] = v;
 		cnt ++;
 	}

 	ll ans = 1e18;
 	if(cnt == n - 1)
 	{
 		ans = min(ans, (ll)k - mxv);
 		rep(i, pos, m) ans = min(ans, (ll)e[i].w - k);
 	}
 	else
 	{
 		ll sum = 0;
 		rep(i, pos, m)
 		{
 			int u = find(e[i].x);
 			int v = find(e[i].y);
 			if(u == v) continue;
 			f[u] = v;
 			sum += e[i].w - k;
 			cnt ++;
 			if(cnt == n - 1) break;
 		}
 		if(cnt == n - 1) ans = min(ans, sum);
 	}
 	if(ans == 1e18) ans = -1;
 	cout << ans << endl;
}

int main()
{
	int T = read();
	while(T --)
	{
		mian();
	}
	return 0;
}