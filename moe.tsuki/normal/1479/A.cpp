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

int n;

void input()
{
	cin >> n;
}

void gao(int l, int r)
{
//	dbgg(l); dbg(r);
	if (r - l <= 2) 
	{
		cout << '!' << ' ' << l + 1 << '\n';
		fflush(stdout);
		return;
	}
	int m = (l + r) / 2;
	cout << "? " << m << '\n';
	fflush(stdout);
	int a, b;
	cin >> a;
	if (m + 1 == n + 1) b = n + 1;
	else
	{
		cout << "? " << m + 1 << '\n';
		fflush(stdout);
		cin >> b;
	}
	if (a < b) gao(l, m + 1);
	else gao(m, r);
}

void solve()
{
	gao(0, n + 1);
}

main()
{
	input();
	solve();
}