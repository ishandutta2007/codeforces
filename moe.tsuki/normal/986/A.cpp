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

const int maxn = 123456, oo = 1e9;
int n, m, s, k;
int a[maxn];
vi E[maxn];
vi li[maxn];
int dis[maxn];
vi dist[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> s;
	F1 (i, n) cin >> a[i];
	F1 (i, m)
	{
		int x, y;
		cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

void solve()
{
	//F1 (i, n) sz[i] = E[i].size();
	F1 (i, n) li[a[i]].pb(i);
	F1 (i, k)
	{
		for (int x : li[i]) 
			E[i + n].pb(x);
		queue<pair<int, int> > que;
		que.push(mp(i + n, -1));
		F1 (j, n) dis[j] = oo;
		while (!que.empty())
		{
			pii x = que.front(); que.pop();
			int cur = x.fi, len = x.se;
			for (int nxt : E[cur])
			{
				if (dis[nxt] > len + 1)
				{
					dis[nxt] = len + 1;
					que.push(mp(nxt, len + 1));
				}
			}
		}
		//dbg(i);
		//F1 (j, n) dbg(dis[j]);
		F1 (j, n) dist[j].pb(dis[j]);
	}
	F1 (i, n)
	{
		sort(all(dist[i]));
		int ans = 0;
		F1 (j, s) ans += dist[i][j - 1];
		cout << ans << ' ';
	}
	
}

main()
{
	input();
	solve();
}