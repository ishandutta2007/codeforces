#pragma GCC optimize("Ofast,no-stack-protector")
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
#define MEOW { cout << "meowwwww" << '\n'; system("pause"); }
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

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

const int maxn = 234, o = 1000000000, oo = o * 123456ll;
string s[maxn];

template <typename Cap = int64_t>
class Dinic
{
	public:
	struct E
	{
		int to, rev;
		Cap cap;
	};
	int n, st, ed;
	vector<vector<E>> G;
	vector<int> lv, idx;
	bool BFS()
	{
		lv.assign(n, -1);
		queue<int> bfs;
		bfs.push(st); lv[st] = 0;
		while (not bfs.empty())
		{
			int u = bfs.front(); bfs.pop();
			for (auto e: G[u])
			{
				if (e.cap <= 0 or lv[e.to]!=-1) continue;
				bfs.push(e.to); lv[e.to] = lv[u] + 1;
			}
		}
		return lv[ed] != -1;
	}
	Cap DFS(int u, Cap f)
	{
		if (u == ed) return f;
		Cap ret = 0;
		for(int &i = idx[u]; i < (int)(G[u].size()); ++i)
		{
			auto &e = G[u][i];
			if (e.cap <= 0 or lv[e.to]!=lv[u]+1) continue;
			Cap nf = DFS(e.to, min(f, e.cap));
			ret += nf; e.cap -= nf; f -= nf;
			G[e.to][e.rev].cap += nf;
			if (f == 0) return ret;
		}
		if (ret == 0) lv[u] = -1;
		return ret;
	}
	void init(int n_) { G.assign(n = n_, vector<E>()); }
	void add_edge(int u, int v, Cap c)
	{
		G[u].push_back({v, (int)(G[v].size()), c});
		G[v].push_back({u, (int)(G[u].size())-1, 0});
	}
	Cap max_flow(int st_, int ed_)
	{
		st = st_, ed = ed_; Cap ret = 0;
		while (BFS())
		{
			idx.assign(n, 0);
			Cap f = DFS(st, numeric_limits<Cap>::max());
			ret += f;
			if (f == 0) break;
		}
		return ret;
	}
};

int n, m;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, n) cin >> s[i];
}

#define code(x,y) ((m+2)*(x)+(y)+1)

void solve()
{
	F1 (i, n) s[i] = "." + s[i] + ".";
	F1 (i, m + 2) s[0] += '.';
	F1 (i, m + 2) s[n + 1] += '.';
	Dinic D;
	int T = 2 * (n + 2) * (m + 2) + 1;
	D.init(T + 1);
	F (i, n + 2)
		F (j, m + 2)
		{
			if (s[i][j] == '.')
			{
				D.add_edge(0, 2 * code(i, j) - 1, oo);
				D.add_edge(2 * code(i, j), T, oo);
			} else
			{
				D.add_edge(0, 2 * code(i, j) - 1, o);
				D.add_edge(2 * code(i, j) - 1, 2 * code(i, j), oo);
				D.add_edge(2 * code(i, j), T, o);
				for (int dx = -1; dx <= 1; ++dx)
					for (int dy = -1; dy <= 1; ++dy)
						if (dx * dx + dy * dy == 1)
							if (dx) D.add_edge(2 * code(i, j) - 1, 2 * code(i + dx, j + dy), 1);
							else D.add_edge(2 * code(i + dx, j + dy) - 1, 2 * code(i, j), 1);
			}
		}
	cout << (D.max_flow(0, T) % o) / 2 << '\n';
}

main()
{
	input();
	solve();
}