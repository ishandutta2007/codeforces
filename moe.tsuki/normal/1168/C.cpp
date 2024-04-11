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

const int maxn = 300001, zog = 19;
int a[maxn];
int n, q;
int val[maxn][zog];
//int r[maxn][zog];
vector<int> L[maxn];
vector<int> R[maxn];
int rig[zog];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	F1 (i, n) cin >> a[i];
}

void gao(int l, int r, int lev)
{
	if (l == r) return;
	int m = (l + r) >> 1;
	gao(l, m, lev + 1);
	gao(m + 1, r, lev + 1);
	for (int i = l; i <= r; ++i)
		val[i][lev] = a[i];
	for (int i = m; i >= l; --i)
	{
		for (auto x : R[i])
			if (x <= m) val[i][lev] |= val[x][lev];
	}
	for (int i = m + 1; i <= r; ++i)
	{
		for (auto x : L[i])
			if (x > m) val[i][lev] |= val[x][lev];
	}
}

bool query(int l, int r, int lev, int x, int y)
{
	int m = (l + r) >> 1;
	if (x <= m && m < y)
	{
		return val[x][lev] & val[y][lev];
	} else if (m >= y)
	{
		return query(l, m, lev + 1, x, y);
	} else 
		return query(m + 1, r, lev + 1, x, y);
}

void solve()
{
	F (i, zog) rig[i] = n + 1; 
	for (int i = n; i >= 1; --i)
	{
		F (j, zog) val[i][j] = rig[j];
		int cur = a[i];
		int cnt = zog;
		while (cnt --> 0)
		{
			if (cur & 1) rig[zog - 1 - cnt] = i;	
			cur >>= 1;
		}
	}
	F1 (i, n)
		F (j, zog) if (val[i][j] != n + 1 && (a[i] & (1 << j))) R[i].pb(val[i][j]);
	F1 (i, n)
		for (auto x : R[i])
			L[x].pb(i);
	gao(1, n, 0);
	F1 (i, q)
	{
		int x, y;
		cin >> x >> y;
		if (x == y) cout << "Shi\n";
		else if (query(1, n, 0, x, y)) cout << "Shi\n";
		else cout << "Fou\n";
	}
}

main()
{
	input();
	solve();
}