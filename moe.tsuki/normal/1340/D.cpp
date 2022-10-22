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

const int maxn = 123456;
int n;
vi E[maxn];
vector<pii> ans;

void dfs(int cur, int tim, int par)
{
	// tim - 1 when back to par
	// tim, tim - 1 taken
	// 0 to tim - 1 and tim + 1 ~
	ans.pb(mp(cur, tim));
	if (cur == 1)
	{
		for (auto x : E[cur]) if (x != par)
			dfs(x, ++tim, cur);
		return;
	}
	int beg;
	int lft = 0;
	if (E[cur].size() - 1 > tim - 1)
	{
		lft = E[cur].size() - tim;
		beg = tim;
	} else
	{
		beg = tim - E[cur].size();
		ans.pb(mp(cur, beg));
	}
	for (auto x : E[cur]) if (x != par)
	{
		if (lft)
		{
			dfs(x, beg + 1, cur);
			--lft;
			++beg;
			if (lft == 0)
			{
				ans.pb(mp(cur, 0));
				beg = 0;
			}
		} else
		{
			dfs(x, beg + 1, cur);
			--lft;
			++beg;
		}
	}
	if (par) ans.pb(mp(par, tim));
} 

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n; 
	F1 (i, n - 1)
	{
		int u, v; cin >> u >> v;
		E[u].pb(v);
		E[v].pb(u);
	}
}

void solve()
{
	dfs(1, 0, 0);
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x.fi << ' ' << x.se << '\n';
}

main()
{
	input();
	solve();
}