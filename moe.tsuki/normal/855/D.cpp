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
#define MEOW cout << "meowwwww" << '\n'; //system("pause");
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

const int maxn = 123456, LOG = 18;
int n, q, cnt, in[maxn], out[maxn];
bool vis[maxn];
pii par[maxn][LOG];
vi E[maxn]; 

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int p, t;
	F1 (i, n)
	{
		cin >> p >> t;
		if (p != -1) 
		{
			par[i][0] = mp(p, t);
			E[p].pb(i);
		}
		else par[i][0] = mp(i, 0);
	}
	//dbg(par[1][0]);
	//dbg(par[2][0]);
	//dbg(par[3][0]);
	cin >> q;
}

void dfs(int cur)
{
	in[cur] = ++cnt;
	vis[cur] = true;
	for (int i : E[cur])
		dfs(i);
	out[cur] = ++cnt;
}

bool anc(int a, int b)
{
	return in[a] <= in[b] && out[a] >= out[b];
}

pair<int, pii> lca(int a, int b)
{
	if (anc(b, a)) return mp(b, mp(0, 0));
	int l = LOG;
	pair<int, pii> ret;
	ret.se.fi = ret.se.se = 0;
	while (l --> 0)
	{
		if (!anc(par[b][l].fi, a))
		{	
			ret.se.fi += par[b][l].se;
			ret.se.se += 1 << l;
			b = par[b][l].fi;
		}
	}
	ret.fi = par[b][0].fi;
	ret.se.fi += par[b][0].se;
	ret.se.se += 1;
	return ret;
}

void solve()
{
	F1 (i, n) if (!vis[i] && par[i][0].fi == i) dfs(i);
	F1 (i, LOG - 1) F1 (j, n)
		par[j][i] = mp(par[par[j][i - 1].fi][i - 1].fi, 
								par[j][i - 1].se + par[par[j][i - 1].fi][i - 1].se);
	F1 (i, q)
	{
		int type, a, b; cin >> type >> a >> b;
		if (type == 1) // if B is a sc of A
		{
			pair<int, pii> rou = lca(a, b);	
			if (rou.fi == a && rou.se.fi == 0 && a != b) cout << "YES\n";
			else cout << "NO\n"; 
		} else // if B is a part of A
		{
			pair<int, pii> rou1 = lca(a, b); // should be a path of only parts (1)
			pair<int, pii> rou2 = lca(b, a);
			if (rou1.fi == rou2.fi && 
					rou1.se.fi == rou1.se.se && rou2.se.fi == 0 && !anc(b, a))
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

main()
{
	input();
	solve();
}