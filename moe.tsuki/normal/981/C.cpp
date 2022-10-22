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

vi ans;
bool ok = true;
int root;
vi E[maxn];
int deg[maxn];

void dfs(int cur, int pa)
{
	int cnt = 0;
	for (int x : E[cur])
	{
		if (x != pa) dfs(x, cur), ++cnt;
	}
	if (cnt == 0) ans.pb(cur);
	if (cnt > 1 && cur != root) ok = false;
}

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n - 1)
	{
		int x, y;
		cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
		++deg[x];
		++deg[y];
	}
}

void solve()
{
	pii md = mp(0, 0);
	F1 (i, n) md = max(md, mp(deg[i], i));
	root = md.se;
	dfs(md.se, 0);
	if (ok) 
	{
		cout << "Yes\n";
		cout << ans.size() << '\n';
		for (int x : ans) cout << md.se << ' ' << x << '\n';
	} else cout << "No\n";
}

main()
{
	input();
	solve();
}