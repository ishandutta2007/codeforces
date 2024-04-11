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
const int N = 1555;
int n, m, a[N][N], b[N][N], c[N], d[N], cc[N], e[N];
bitset<N> t[N], s;
vector<int> v;
bool cmpa(int i, int j) 
{
	rep(k, 1, m)
		if (a[i][k] != a[j][k])
			return a[i][k] < a[j][k];
	return 0;
}
bool cmpb(int i, int j) 
{
	rep(k, 1, m)
		if (b[i][k] != b[j][k])
			return b[i][k] < b[j][k];
	return 0;
}
int main() 
{
	n = read();
	m = read();
	rep(i, 1, n)
		rep(j, 1, m)
			a[i][j] = read();
	rep(i, 1, n)
		rep(j, 1, m)
			b[i][j] = read();
	rep(i, 1, n) c[i] = i, d[i] = i;
	stable_sort(c + 1, c + n + 1, cmpa);
	stable_sort(d + 1, d + n + 1, cmpb);
	rep(i, 1, n)
	{
		b[d[i]][0] = c[i];
		rep(j, 1, m)
			if (a[c[i]][j] != b[d[i]][j]) 
			{
				puts("-1");
				return 0;
			}
	}
	rep0(j, m + 1)
		rep(i, 1, n - 1)
			if (b[i][j] <= b[i + 1][j])
				t[j][i] = 1;
	rep(i, 1, n - 1) s[i] = 1;
	rep0(i, m + 1)
	{
		int x = 0;
		rep0(j, m + 1)
		{
			if (e[j]) continue;
			if ((t[j] & s) == s) 
			{
				v.pb(j);
				e[j] = 1;
				rep(k, 1, n - 1)
					if (b[k][j] < b[k + 1][j])
						s[k] = 0;
				x = 1;
				break;
			}
		}
		if (e[0] == 1) break;
		if (!x)  
		{
			cout << -1;
			return 0;
		}
	}
	cout << v.size() - 1 << endl;
	rrep(i, sz(v) - 2, 0) cout << v[i] << ' ';
	return 0;
}