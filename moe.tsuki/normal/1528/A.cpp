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
int t;
int l[maxn], r[maxn];
bool vis[maxn];
vi E[maxn];
int dp[maxn][2];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void dfs(int cur)
{
	//dbg(cur);
	vis[cur] = true;
	dp[cur][0] = dp[cur][1] = 0;
	for (auto x : E[cur]) if (!vis[x])
	{
		dfs(x);
		int k;
		k = max(dp[x][0] + abs(l[x] - l[cur]), dp[x][1] + abs(r[x] - l[cur]));
		dp[cur][0] += k;
		k = max(dp[x][0] + abs(l[x] - r[cur]), dp[x][1] + abs(r[x] - r[cur]));
		dp[cur][1] += k;
	}
}

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> l[i] >> r[i];
		F1 (i, n) E[i].clear();
		F1 (i, n - 1)
		{
			int x, y; cin >> x >> y;
			E[x].pb(y);
			E[y].pb(x);
		}
		F1 (i, n) vis[i] = false;
		dfs(1);
		cout << max(dp[1][0], dp[1][1]) << '\n';
		//F1 (i, n) dbg(mp(dp[i][0], dp[i][1]));
	}
}

main()
{
	input();
	solve();
}