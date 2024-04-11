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

int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

int n, m;

vector<pii> x[3];
string s[12345];

void gao(int i, int j)
{
	// default
	int a, b, c, d;
	a = b = i; c = d = j;
	if (i == 0) ++b;
	else --a;
	if (j == 0) ++d;
	else --c;
	int cur = 0;
	for (int p = a; p <= b; ++p)
		for (int q = c; q <= d; ++q)
			if (i != p || j != q)
			{
				for (int r = a; r <= b; ++r)
					for (int s = c; s <= d; ++s)
						if (r != p || s != q)
							x[cur].pb(mp(r + 1, s + 1));
				++cur;				
			}
	s[i][j] = '0' + '1' - s[i][j];
}

void solve()
{
	while (t --> 0)
	{
		cin >> n >> m;
		x[0].clear();
		x[1].clear();
		x[2].clear();
		F (i, n)
			cin >> s[i];
		F (i, n)
			F (j, m)
			{
				if (s[i][j] == '1')
				{
					gao(i, j);
				}
			}
		cout << x[0].size() << '\n';
		//dbg(x[0].size());
		F (i, x[0].size() / 3)
		{
		cout << x[0][i + i + i + 0].fi << ' ' << x[0][i + i + i + 0].se << ' ';
		cout << x[0][i + i + i + 1].fi << ' ' << x[0][i + i + i + 1].se << ' ';
		cout << x[0][i + i + i + 2].fi << ' ' << x[0][i + i + i + 2].se << '\n';
		cout << x[1][i + i + i + 0].fi << ' ' << x[1][i + i + i + 0].se << ' ';
		cout << x[1][i + i + i + 1].fi << ' ' << x[1][i + i + i + 1].se << ' ';
		cout << x[1][i + i + i + 2].fi << ' ' << x[1][i + i + i + 2].se << '\n';
		cout << x[2][i + i + i + 0].fi << ' ' << x[2][i + i + i + 0].se << ' ';
		cout << x[2][i + i + i + 1].fi << ' ' << x[2][i + i + i + 1].se << ' ';
		cout << x[2][i + i + i + 2].fi << ' ' << x[2][i + i + i + 2].se << '\n';
		}
	}
}

main()
{
	input();
	solve();
}