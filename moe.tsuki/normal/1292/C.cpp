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

const int maxn = 3456;
int n;
vi E[maxn];
int tim;
int in[maxn], out[maxn];
int dep[maxn];
vi son[maxn];
vi ch[maxn];
vector<pii> dis[maxn + maxn];
int ans[maxn][maxn];
int nxt[maxn][maxn];
int fa[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n - 1)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

void dfs(int cur)
{
	in[cur] = ++tim;
	ch[cur].pb(cur);
	for (auto x : E[cur]) if (!in[x])
	{
		dep[x] = dep[cur] + 1; 
		fa[x] = cur;
		dfs(x);
		son[cur].pb(x);
		for (auto y : ch[x])
			ch[cur].pb(y);
	}
	for (auto x : ch[cur])
		dis[dep[x] - dep[cur]].pb(mp(cur, x));
	for (int i = 0; i < son[cur].size(); ++i)
		for (int j = i + 1; j < son[cur].size(); ++j)
			for (auto x : ch[son[cur][i]])
				for (auto y : ch[son[cur][j]])
					dis[dep[x] + dep[y] - dep[cur] - dep[cur]].pb(mp(x, y));
	for (auto x : son[cur])
		for (auto y : ch[x])
		{
			nxt[cur][y] = x;
			//dbgg(cur); dbgg(y); dbg(nxt[cur][y]);
		}
	out[cur] = ++tim;
}

int getsz(int a, int b)
{
	if (in[a] <= in[b] && out[b] <= out[a])
	{
		return n - ch[nxt[a][b]].size(); 
	} else return ch[a].size();
}

int closer(int a, int b)
{
	if (in[a] <= in[b] && out[b] <= out[a])
	{
		return nxt[a][b]; 
	} else return fa[a];
}

void solve()
{
	dfs(1);
	for (int i = maxn * 2; i >= 1; --i)
	{
		for (auto cur : dis[i])
		{
			//dbgg(cur); dbg(i);
			int add = getsz(cur.fi, cur.se) * getsz(cur.se, cur.fi);
			//dbg(ans[cur.fi][cur.se]);
			ans[cur.fi][cur.se] += add;
			ans[cur.se][cur.fi] += add;
			//dbg(add);
			//dbg(ans[cur.fi][cur.se]);
			int x = closer(cur.fi, cur.se);
			ans[x][cur.se] = max(ans[x][cur.se], ans[cur.fi][cur.se]);
			ans[cur.se][x] = max(ans[cur.se][x], ans[cur.fi][cur.se]);
			int y = closer(cur.se, cur.fi);
			ans[y][cur.fi] = max(ans[y][cur.fi], ans[cur.fi][cur.se]);
			ans[cur.fi][y] = max(ans[cur.fi][y], ans[cur.fi][cur.se]);
			//MEOW;
			//dbg(x); dbg(y);
			//MEOW;
		}
	}
	int out = 0;
	F1 (i, n)
		for (auto x : E[i])
			out = max(out, ans[i][x]);
	cout << out << '\n';
}

main()
{
	input();
	solve();
}