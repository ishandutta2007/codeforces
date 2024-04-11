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

const int maxn = 345678;
int t;
vi E[maxn];
int c[maxn];
bool in[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n, m; cin >> n >> m;
		F1 (i, n) E[i].clear();
		F1 (i, m)
		{
			int u, v; cin >> u >> v;
			E[u].pb(v); E[v].pb(u);
		}
		F1 (i, n) c[i] = -1;
		F1 (i, n) in[i] = false;
		priority_queue<int, vi, greater<int> > pq;
		pq.push(1);
		in[1] = true;
		int ans = 0;
		while (!pq.empty())
		{
			int cur = pq.top();
			pq.pop();
			//dbg(cur);
			if (c[cur] == 0) continue;
			c[cur] = 1;
			++ans;
			for (auto x : E[cur])
			{
				if (c[x] == -1)
				{
					in[x] = true;
					c[x] = 0;
					++ans;
					for (auto y : E[x])
						if (!in[y])
						{
							pq.push(y);
							in[y] = true;
						}
				}
			}
		}
		if (ans == n)
		{
			cout << "YES\n";
			vi v;
			F1 (i, n) if (c[i] == 1) v.pb(i);
			cout << v.size() << '\n';
			for (auto x : v) cout << x << ' ';
			cout << '\n';
		} else cout << "NO\n";
	}
}

main()
{
	input();
	solve();
}