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

const int maxn = 567890;
int n, m, k;
int a[maxn];
vi E[maxn];
int id[maxn];
bool vis[maxn];
int c[maxn];
bool ok[maxn];
int cnt;
map<pii, vector<pii>> mm;
int tmp[maxn];
vector<pii> F[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	F1 (i, n) cin >> a[i];
	F1 (i, m)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

void dfs(int cur, int v)
{
	id[cur] = v;
	vis[cur] = true;
	for (auto x : E[cur])
	{
		if (a[x] == a[cur])
		{
			if (!vis[x])
			{
				c[x] = c[cur] ^ 1;
				dfs(x, v);
			} else if (c[x] == c[cur])
				ok[a[cur]] = false;
		}
	}
}

bool dfs2(int cur)
{
	bool ret = true;
	if (tmp[cur] == -1)
		tmp[cur] = 0;
	for (auto x : F[cur])
	{
		if (tmp[x.fi] == -1)
		{
			tmp[x.fi] = tmp[cur] ^ x.se;
			ret &= dfs2(x.fi);
		} else if (tmp[x.fi] != (tmp[cur] ^ x.se))
		{
			//dbg(mp(x.fi, cur));
			ret = false;	
		}
	} 
	return ret;
}

void solve()
{
	//F1 (i, n) dbg(E[i]);
	//F1 (i, n) dbg(a[i]);
	F1 (i, k) ok[i] = true;
	F1 (i, n)
	{
		if (!vis[i])
		{
			dfs(i, ++cnt);
			//dbg(mp(i, cnt));
		}
	}
	int tot = k;
	F1 (i, k) if (!ok[i]) --tot;
	//dbg(tot);
	int ans = tot * (tot - 1) / 2;
	// calc not ok pair
	//F1 (i, n) dbg(id[i]);
	//F1 (i, n) dbg(c[i]);
	F (i, maxn) tmp[i] = -1;
	F1 (i, n)
	{
		if (!ok[a[i]]) continue;
		for (auto x : E[i])
		{
			if (!ok[a[x]]) continue;
			if (a[i] == a[x]) continue;
			mm[mp(min(a[i], a[x]), max(a[i], a[x]))].pb(mp(i, x));
		}
	}
	for (auto x : mm)
	{
		//dbg(x.fi);
		//dbg(x.se);
		bool ok = true;
		for (auto cur : x.se)
		{
			F[id[cur.fi]].pb(mp(id[cur.se], 1 ^ c[cur.fi] ^ c[cur.se]));
			F[id[cur.se]].pb(mp(id[cur.fi], 1 ^ c[cur.fi] ^ c[cur.se]));
			//dbg(mp(id[cur.fi], mp(id[cur.se], 1 ^ c[cur.fi] ^ c[cur.se])));
			//dbg(mp(id[cur.se], mp(id[cur.fi], 1 ^ c[cur.fi] ^ c[cur.se])));
		}
		for (auto cur : x.se)
		{
			if (tmp[id[cur.fi]] == -1)
			{
				ok &= dfs2(id[cur.fi]);
				//dbg(id[cur.fi]);
			}
		}
		//dbg(ok);
		for (auto cur : x.se)
		{
			F[id[cur.fi]].clear();
			F[id[cur.se]].clear();
			tmp[id[cur.fi]] = tmp[id[cur.se]] = -1;
		}
		if (!ok) --ans;
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}