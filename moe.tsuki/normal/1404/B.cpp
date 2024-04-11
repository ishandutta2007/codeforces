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
int n, a, b, p, q;
int t;
int dis[maxn];
vi E[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void dfs(int cur, int fa)
{
	dis[cur] = dis[fa] + 1;
	for (auto x : E[cur])
		if (x != fa)
			dfs(x, cur);
}

void solve()
{
	while (t --> 0)
	{
		cin >> n >> a >> b >> p >> q;
		F1 (i, n) E[i].clear();
		F1 (i, n - 1)
		{
			int u, v; cin >> u >> v;
			E[u].pb(v);
			E[v].pb(u);
		}
		if (q <= p * 2)
		{
			cout << "Alice\n";
			continue;
		}
		dfs(1, 0);
		pii x = mp(0, 0);
		F1 (i, n) x = max(x, mp(dis[i], i));
		dfs(x.se, 0);
		F1 (i, n) x = max(x, mp(dis[i], i));
		dfs(a, 0);
		if (dis[b] - 1 <= p) cout << "Alice\n";
		else if ((x.fi - 1) <= p + p) cout << "Alice\n";
		else cout << "Bob\n";
	}
}

main()
{
	input();
	solve();
}