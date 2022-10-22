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

vector<pii> x;
string s[12345];

void gao1(int i, int j)
{
	// default
	x.pb(mp(i, j));
	s[i][j] = '0' + '1' - s[i][j];
	x.pb(mp(i - 1, j));
	s[i - 1][j] = '0' + '1' - s[i - 1][j];
	int nxt = j - 1;
	if (nxt < 0) nxt += 2;
	x.pb(mp(i - 1, nxt));
	s[i - 1][nxt] = '0' + '1' - s[i - 1][nxt];
}

void gao2(int i, int j)
{
	// default
	/*if (i == n - 1 && j == m - 1)
	{
		x.pb(mp(i, j));
		s[i][j] = '0' + '1' - s[i][j];
		x.pb(mp(i - 1, j));
		s[i - 1][j] = '0' + '1' - s[i - 1][j];
		x.pb(mp(i - 1, j - 1));
		s[i - 1][j - 1] = '0' + '1' - s[i - 1][j - 1];
		return;
	}*/
	x.pb(mp(i, j));
	s[i][j] = '0' + '1' - s[i][j];
	x.pb(mp(i, j - 1));
	s[i][j - 1] = '0' + '1' - s[i][j - 1];
	int nxt = i - 1;
	if (nxt < 0) nxt += 2;
	x.pb(mp(nxt, j - 1));
	s[nxt][j - 1] = '0' + '1' - s[nxt][j - 1];
}

void fu(int i, int j)
{
	int cnt = 0;
	if (s[i + i + 0][j + j + 0] == '1') ++cnt;
	if (s[i + i + 0][j + j + 1] == '1') ++cnt;
	if (s[i + i + 1][j + j + 0] == '1') ++cnt;
	if (s[i + i + 1][j + j + 1] == '1') ++cnt;
	if (cnt == 0) return;
	if (cnt == 1)
	{
		for (int p = i + i; p <= i + i + 1; ++p)
			for (int q = j + j; q <= j + j + 1; ++q)
				if (s[p][q] == '0')
				{
					for (int r = i + i; r <= i + i + 1; ++r)
						for (int s = j + j; s <= j + j + 1; ++s)
							if (r != p || s != q)
								x.pb(mp(r, s));				
				}	
	}
	if (cnt == 2)
	{
		int f = 0, u = 0;
		for (int p = i + i; p <= i + i + 1; ++p)
			for (int q = j + j; q <= j + j + 1; ++q)
			{
				if (s[p][q] == '1')
					f += p, u += q;
			}
		if ((f & 1) && (u & 1))
			for (int p = i + i; p <= i + i + 1; ++p)
				for (int q = j + j; q <= j + j + 1; ++q)
				{
					if (s[p][q] == '1')
					{
						x.pb(mp(p, q));
						x.pb(mp(4 * i + 1 - p, q));
						x.pb(mp(p, 4 * j + 1 - q));
					}
				}
		else
			for (int p = i + i; p <= i + i + 1; ++p)
				for (int q = j + j; q <= j + j + 1; ++q)
				{
					if (s[p][q] == '0')
					{
						x.pb(mp(p, q));
						x.pb(mp(4 * i + 1 - p, q));
						x.pb(mp(p, 4 * j + 1 - q));
					}
				}
	}
	if (cnt == 3)
	{
		for (int p = i + i; p <= i + i + 1; ++p)
			for (int q = j + j; q <= j + j + 1; ++q)
				if (s[p][q] == '0')
				{
					x.pb(mp(4 * i + 1 - p, 4 * j + 1 - q));
					x.pb(mp(4 * i + 1 - p, q));
					x.pb(mp(p, 4 * j + 1 - q));
				}
	}
	if (cnt == 4)
	{
		for (int p = i + i; p <= i + i + 1; ++p)
			for (int q = j + j; q <= j + j + 1; ++q)
			{
				x.pb(mp(4 * i + 1 - p, 4 * j + 1 - q));
				x.pb(mp(4 * i + 1 - p, q));
				x.pb(mp(p, 4 * j + 1 - q));
			}
	}
}

void solve()
{
	while (t --> 0)
	{
		cin >> n >> m;
		F (i, n)
			cin >> s[i];
		/*F (i, n)
			F (j, m)
			{
				if (s[i][j] == '1')
				{
					gao(i, j);
				}
			}*/
		x.clear();
		if (n & 1)
		{
			for (int i = 0; i < m; ++i)
				if (s[n - 1][i] == '1')
					gao1(n - 1, i);
		}
		if (m & 1)
		{
			int i = n - 1;
			if (n & 1) --i;
			for (; i >= 0; --i)
				if (s[i][m - 1] == '1')
				{
					gao2(i, m - 1);
				}
		}
		F (i, n / 2)
			F (j, m / 2)
				fu(i, j);
		cout << x.size() / 3 << '\n';
		F (i, x.size() / 3)
		{
		cout << x[i + i + i + 0].fi + 1 << ' ' << x[i + i + i + 0].se + 1 << ' ';
		cout << x[i + i + i + 1].fi + 1 << ' ' << x[i + i + i + 1].se + 1 << ' ';
		cout << x[i + i + i + 2].fi + 1 << ' ' << x[i + i + i + 2].se + 1 << '\n';
		}
	}
}

main()
{
	input();
	solve();
}