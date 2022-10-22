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

struct c3
{
	int a, b, c;
};

struct c4
{
	int a, b, c, d;
};

int n;
vector<pii> gon;
vector<c3> C3;
vector<c4> C4;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
}

void cyc3(int a, int b, int c)
{
	C3.pb({a, b, c});
}

void cyc4(int a, int b, int c, int d)
{
	C4.pb({a, b, c, d});
}

void quad(int x)
{
	int a = x, b = x + 1, c = x + 2, d = x + 3;
	cyc4(a, b, c, d);
	cyc4(a, b, d, c);
	cyc4(a, c, b, d);
}

void penta(int x)
{
	int a = x, b = x + 1, c = x + 2, d = x + 3, e = x + 4;
	cyc3(a, b, c); cyc3(a, b, c);
	cyc3(a, d, e); cyc3(a, d, e);
	cyc4(b, d, c, e); cyc4(b, d, c, e);
}

void hexa(int x)
{
	int a = x, b = x + 1, c = x + 2, d = x + 3, e = x + 4, f = x + 5;
	cyc3(a, b, c);
	cyc3(b, c, d);
	cyc3(c, d, e);
	cyc3(d, e, f);
	cyc3(e, f, a);
	cyc3(f, a, b);
	cyc4(a, d, b, e);
	cyc4(b, e, c, f);
	cyc4(c, f, d, a);
}

void rot(int a, int b, int c)
{
	for (int i = 1; i <= a - 1; ++i)
	{
		cyc4(b + i - 1, c, b + i, c + 3);
		cyc4(b + i - 1, c + 1, b + i, c + 2);
	}
	cyc4(b + a - 1, c, b, c + 3);
	cyc4(b + a - 1, c + 1, b, c + 2);
}

void solve()
{
	int sqr;
	if (n % 4 == 0)
	{
		sqr = n / 4;
	} else if (n % 4 == 1)
	{
		sqr = (n - 5) / 4;
		gon.pb(mp(5, n - 4));
		penta(n - 4);
	} else if (n % 4 == 2)
	{
		sqr = (n - 6) / 4;
		gon.pb(mp(6, n - 5));
		hexa(n - 5);
	} else if (n % 4 == 3)
	{
		sqr = (n - 3) / 4;
		gon.pb(mp(3, n - 2));
		cyc3(n - 2, n - 1, n);
		cyc3(n - 2, n - 1, n);
	}
	
	for (int i = 0; i < sqr; ++i)
	{
		gon.pb(mp(4, 4 * i + 1));
		quad(4 * i + 1);
	}
	for (int i = 0; i < gon.size(); ++i)
	{
		for (int j = i + 1; j < gon.size(); ++j)
			rot(gon[i].fi, gon[i].se, gon[j].se);
	}
	cout << C3.size() + C4.size() << '\n';
	for (auto x : C3)
		cout << 3 << ' ' << x.a << ' ' << x.b << ' ' << x.c << '\n';
	for (auto x : C4)
		cout << 4 << ' ' << x.a << ' ' << x.b << ' ' << x.c << ' ' << x.d << '\n';
}

main()
{
	input();
	solve();
}