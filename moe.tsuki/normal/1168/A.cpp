#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW cout << "meowwwww" << '\n'; system("pause");
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

const int maxn = 345678;
int n, m;
int a[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, n) cin >> a[i];
}

int clamp(int a, int b, int c)
{
	if (a > c)
		return a;
	if (b < c)
		return -1;
	return c;
}

bool ok(int v)
{
	int cur = 0;
	F1 (i, n)
	{
		if (a[i] + v < m)
		{
			int val = clamp(a[i], a[i] + v, cur);
			if (val == -1) return false;
			else cur = val;
		} else
		{
			int p = clamp(0, (a[i] + v) % m, cur);
			int q = clamp(a[i], m - 1, cur);
			if (p == -1 && q == -1) return false;
			if (p == -1) cur = q;
			else if (q == -1) cur = p;
			else cur = min(p, q);
		}
	}
	return true;
}

void solve()
{
	int ans = m;
	int d = 1;
	while (d <= ans) d <<= 1;
	d >>= 1;
	while (d)
	{
		if (ans >= d && ok(ans - d)) ans -= d;
		d >>= 1;
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}