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

const int maxn = 234567;
int n, m, k;
vi E[maxn], F[maxn];
int p[maxn];
int dist[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, m)
	{
		int x, y; cin >> x >> y;
		E[y].pb(x);
		F[x].pb(y);
	}	
	cin >> k;
	F1 (i, k) cin >> p[i];
}

void solve()
{
	int ans1 = 0, ans2 = 0;
	queue<int> q;
	q.push(p[k]);
	dist[p[k]] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto x : E[cur])
		{
			if (!dist[x]) 
			{
				dist[x] = dist[cur] + 1;
				q.push(x);
			}
		}
	}
	F1 (i, k - 1)
	{
		int need = dist[p[i]] - 1;
		int cur = 0;
		if (dist[p[i + 1]] != need) ++ans1;
		else 
		{
			for (auto x : F[p[i]])
			{
				if (dist[x] == need)
					++cur;
			}
			if (cur >= 2) ++ans2;
		} 
	}
	cout << ans1 << ' ' << ans1 + ans2 << '\n';
}

main()
{
	input();
	solve();
}