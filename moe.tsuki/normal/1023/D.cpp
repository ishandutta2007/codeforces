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

const int maxn = 234567, maxl = 20, oo = 100000000;
int n, q;
int a[maxn], l[maxn], r[maxn];
int st[maxn][maxl];
int zog[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	F (i, n) cin >> a[i];
}

int qry(int l, int r)
{
	int z = zog[r - l + 1];
	return min(st[l][z], st[r - (1 << z) + 1][z]);
}

void solve()
{
	int last = 0, pos = -1;
	for (int i = 0; i < n; ++i) if (a[i] == 0) pos = i;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0 && last) a[i] = last;
		if (a[i] != 0) last = a[i];
	}
	
	
		//for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	
	int lft = q;
	for (int i = 0; i < n; ++i)
	{
		if (a[i]) { lft = a[i]; break; }
	}
	for (int i = 0; i < n; ++i)
		if (!a[i]) a[i] = lft;
		
	for (int i = 0; i < n; ++i)
	{
		st[i + 1][0] = a[i];
	}
	for (int j = 1; j < maxl; ++j)
		for (int i = 1; i <= n - (1 << j) + 1; ++i)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	zog[1] = 0;
	for (int i = 2; i < maxn; ++i) zog[i] = zog[i >> 1] + 1;	
	for (int i = 0; i <= q; ++i)
	{
		l[i] = oo, r[i] = -oo;
	}
	for (int i = 0; i < n; ++i)
	{
		l[a[i]] = min(l[a[i]], i + 1);
		r[a[i]] = max(r[a[i]], i + 1);
	}
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		if (qry(l[a[i]], r[a[i]]) != a[i]) 
		{	flag = false;
		}
	}
	int mx = 0;
	for (int i = 0; i < n; ++i) mx = max(mx, a[i]);
	if (mx != q)
	{
		if (pos != -1) a[pos] = q;
		else flag = false; 
	}
	if (flag)
	{	
		cout << "YES\n";
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << '\n';
	} else cout << "NO\n";
}

main()
{
	input();
	solve();
}