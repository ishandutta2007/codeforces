#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e5 + 10;
struct Node 
{
	int x, y;
	Node ()	{}
	Node (int _x, int _y) 
	{
		x = _x, y = _y;
	}
	Node operator +(Node t) 
	{
		return Node(x + t.x, y + t.y);
	}
	Node operator -(Node t) 
	{
		return Node(x - t.x, y - t.y);
	}
	bool operator <(Node t) 
	{
		return x == t.x ? (y < t.y) : (x < t.x);
	}
};
vector <Node> p, q;
vi G[N];
Node f[N][2], ans;
int g[N], rt, nx[N], sx[N], n;
bool vis[N];
void dfs(int t) 
{
	vis[t] = 1; 
	f[t][0] = f[t][1] = Node(0, 0);
	g[t] = 0;
	Node res = Node(0,0);
	rep(i, 0, sz(G[t]) - 1)
	{
		int x = G[t][i]; 
		if (x == rt) continue; 
		dfs(x);
		f[t][1] = f[t][1] + f[x][0];
		Node tmp = Node(1, sx[t] ^ sx[x]) + f[x][1] - f[x][0];
		if (res < tmp) res = tmp, g[t] = x;
	}
	f[t][0] = res + f[t][1];
}
void dfs1(int t,bool flag) 
{
	int x;
	rep(i, 0, sz(G[t]) - 1) 
		if ((x = G[t][i]) ^ rt)
		{
			if (flag) dfs1(x, 0); 
			else if (g[t] == x) p.pb(Node(t, x)), dfs1(x, 1);
			else dfs1(x, 0);
		}
}

void solve(int x) 
{
	while (!vis[x]) vis[x] = 1, x = nx[x];
	Node res = Node(0, 0);
	rep(i, 0, 1) 
	{
		rt = x;
		dfs(rt);
		if (res < f[rt][0]) 
		{
			res = f[rt][0];
			p.clear();
			dfs1(rt, 0);
		}
		x = nx[x];
	}
	rep(i, 0, sz(p) - 1) q.pb(p[i]);
	ans = ans + res;
}

int main() 
{
	n = read();
	ans = Node(0, 0);
	rep(i, 1, n) 
	{
		nx[i] = read();
		sx[i] = read();
		sx[i] --;
		G[nx[i]].pb(i);
	}
	rep(i, 1, n) 
		if (!vis[i]) 
			solve(i);
	printf("%d %d\n", ans.x, ans.y);
	rep(i, 0, sz(q) - 1) printf("%d %d\n", q[i].x, q[i].y);
	return 0;
}