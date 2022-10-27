#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int N = 5e5 + 100;
int n, m, k, f[N], col[N], vis[N], rev1[N], dep[N], fa[N], sz[N], bel[N], son[N], dsu[N];
vector <int> nxt[N], G[N], pot[N];
int getfa(int x)
{
	return x == dsu[x] ? x : dsu[x] = getfa(dsu[x]);
}
void dfs1(int u, int lst)
{
	sz[u] = 1;
	dep[u] = dep[lst] + 1;
	fa[u] = lst;
	for(auto v : nxt[u])
	{
		if(v != fa[u])
		{
			dfs1(v, u);
			sz[u] += sz[v];
			son[u] = sz[son[u]] > sz[v] ? son[u] : v;
		}
	}
}
void dfs2(int u)
{
	bel[u] = son[fa[u]] == u ? bel[fa[u]] : u;
	for(auto v : nxt[u])
	{
		if(v != fa[u])
		{
			dfs2(v);
		}
	}
}
int lca(int x, int y)
{
	while(bel[x] != bel[y])
	{
		if(dep[bel[x]] > dep[bel[y]])
		{
			x = fa[bel[x]];
		}
		else
		{
			y = fa[bel[y]];
		}
	}
	return dep[x] < dep[y] ? x : y;
}
int pa[N], w[N];
vector <pair <int, int> > vec;
void getpa(int x)
{
	if(x == pa[x])
	{
		return;
	}
	getpa(pa[x]);
	w[x] ^= w[pa[x]];
	pa[x] = pa[pa[x]];
}
void down(int u)
{
	for(auto v : nxt[u])
	{
		if(v != fa[u])
		{
			rev1[v] ^= rev1[u];
			down(v);
		}
	}
}
bool dp(int u)
{
	pair <int, int> A = make_pair(1, k);
	pair <int, int> B = make_pair(1, k);
	int turn = 0;
 	rev1[u] = 0;
	for(auto v : nxt[u])
	{
		if(v != fa[u])
		{
			if(!dp(v))
			{
				return 0;
			}
		}
	}
	vec.clear();
	for(auto v : nxt[u])
	{
		if(v != fa[u])
		{
			pot[pa[v]].push_back(v);
			vis[pa[v]] = 0;
		}
	}
	int flg = 0;
	for(auto x : pot[pa[u]])
	{
		if(getfa(u) == getfa(x))
		{
			flg = w[x];
		}
	}
	for(auto x : pot[pa[u]])
	{
		if(w[x] == flg)
		{
			A.X = max(A.X, f[x] + 1);
		}
		else
		{
			A.Y = min(A.Y, k - f[x]);
			rev1[x] ^= 1;
		}
	}
	for(auto v : nxt[u])
	{
		if(v != fa[u] && vis[pa[v]] != u && pa[v] != pa[u])
		{
			vis[pa[v]] =u;
			pair <int, int> now = make_pair(1, k);
			for(auto x : pot[pa[v]])
			{
				if(w[x] == 1)
				{
					now.X = max(now.X, f[x] + 1);
				}
				else
				{
					now.Y = min(now.Y, k - f[x]);
				}
			}
			if(now.X + now.Y > k + 1)
			{
				swap(now.X, now.Y);
				now.X = k + 1 - now.X;
				now.Y = k + 1- now.Y;
			}
				vec.push_back(now);
		}
	}
	for(auto p : vec)
	{
		if(p.X > A.Y || p.Y < A.X)
		{
			turn = 1;
		}
	}
	B = A;
	////cout << u << " " << B.X << " " << B.Y << "\n";
	for(auto v : nxt[u])
	{
		if(v != fa[u])
		{
			vis[pa[v]] = 0;
		}
	}
	for(auto v : nxt[u])
	{
		if(v != fa[u] && vis[pa[v]] != u && pa[v] != pa[u])
		{
			vis[pa[v]] = u;
			pair <int, int> now = make_pair(1, k);
			for(auto x : pot[pa[v]])
			{
				if(w[x] == 1)
				{
					now.X = max(now.X, f[x] + 1);
				}
				else
				{
					now.Y = min(now.Y, k - f[x]);
					rev1[x] ^= 1;
				}
			}
			if(turn ^ (now.X + now.Y > k + 1))
			{
				swap(now.X, now.Y);
				now.X = k + 1 - now.X;
				now.Y = k + 1 - now.Y;
				for(auto x : pot[pa[v]])
				{
					rev1[x] ^= 1;
				}
			}
			B.X = max(B.X, now.X);
			B.Y = min(B.Y, now.Y);
		}
	}
	f[u] = B.X;
	for(auto v : nxt[u])
	{
		if(v != fa[u])
		{
			pot[pa[v]].clear();
		}
	}
	return B.X <= B.Y;
}
	int A[N], B[N];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i= 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		nxt[u].push_back(v);
		nxt[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1);
	for(int i = 1; i <= n; i++)
	{
		dsu[i] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y;
		A[i] = x, B[i] = y;
		z = lca(x, y);
		if(z == x || z == y)
		{
			A[i] = B[i] = 0;
		}
		x = getfa(x);
		while(fa[x] != z && dep[x] > dep[z])
		{
	//	    cout << x << " " << getfa(fa[x]) << "\n";
			dsu[x] = getfa(fa[x]);
			x = getfa(fa[x]);
		}
		y = getfa(y);
		while(fa[y] != z && dep[y] > dep[z])
		{
		//    cout << y << " " << getfa(fa[y]) << "\n";
			dsu[y] = getfa(fa[y]);
			y = getfa(fa[y]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		pa[i] = getfa(i);
	}
	for(int i = 1; i <= m; i++)
	{
		if(A[i] && B[i])
		{
			getpa(A[i]);
			getpa(B[i]);
			if(pa[A[i]] == pa[B[i]])
			{
				if(w[A[i]] == w[B[i]])
				{
					cout << -1;
					return 0;
				}
			}
			else
			{
				if(dep[pa[A[i]]] < dep[pa[B[i]]])
				{
					swap(A[i], B[i]);
				}
				w[pa[A[i]]] ^= (w[A[i]] == w[B[i]]);
				pa[pa[A[i]]] = pa[B[i]];
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		getpa(i);
	}
	int L = 0, R = n;
	while(R - L > 1)
	{
		int midd = k = (R + L) / 2;
		if(dp(1))
		{
			R = midd;
		}
		else
		{
			L = midd;
		}
	}

	cout << (k = R) << endl;
	dp(1);
	down(1);
	for(int i = 1; i <= n; i++)
	{
		f[i] = rev1[i] ? (k + 1 - f[i]) : f[i];
		cout << f[i] << " ";
	}
	return 0;
}