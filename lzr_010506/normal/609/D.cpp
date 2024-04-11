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
#define ALL(x) (x).bEin(), (x).end()
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
const int N = 3e5 + 10;
int n, m, k, s;
pii a[N], b[N];
vector< pair<ll, int> > v[2];

ll Get(const vector<pair<ll, int> > &v, int num)
{
	if(num == 0) return 0;
	return v[num - 1].X;
}

int get(int day)
{
	int x = a[day].X, y = b[day].X;
	for(int i = 0; i <= k && i <= v[0].size(); i ++)
	{
		int j = k - i;
		if(0 <= j && j <= v[1].size())
			if(1LL * x * Get(v[0], i) + 1LL * y * Get(v[1], j) <= s)
				return i;
	}
	return -1;
}

int main()
{
	n = read();
	m = read();
	k = read();
	s = read();
	rep(i, 1, n)
	{
		int t = read();
		if(i == 1 || t < a[i - 1].X) a[i] = mp(t, i);
		else a[i] = a[i - 1];
	}
	rep(i, 1, n)
	{
		int t = read();
		if(i == 1 || t < b[i - 1].X) b[i] = mp(t, i);
		else b[i] = b[i - 1];
	}
	rep(i, 1, m)
	{
		int t = read();
		int c = read();
		v[t - 1].pb(mp(c, i));
	}
	rep0(i, 2)
	{
		sort(v[i].begin(), v[i].end());
		rep(j, 1, (int)v[i].size() - 1)
			v[i][j].X += v[i][j - 1].X;
	}
	int l = 1, r = n;
	int ans = -1;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(get(mid) != -1) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	if(ans == -1) {puts("-1"); return 0;}
	int x = get(ans);
	int y = k - x;
	printf("%d\n", ans);
	rep0(i, x) printf("%d %d\n", v[0][i].Y, a[ans].Y);
	rep0(i, y) printf("%d %d\n", v[1][i].Y, b[ans].Y);


	return 0;
}