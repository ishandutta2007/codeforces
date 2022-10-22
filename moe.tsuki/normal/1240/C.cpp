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
int q;
bool vis[maxn];
vector<pii> E[maxn];
vi son[maxn];
int fa[maxn];
int dp[maxn][2];
 
void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> q;
}
 
int k;
 
void dfs(int cur)
{
	vis[cur] = true;
	for (auto x : E[cur])
	{
		if (vis[x.fi]) continue;
		dfs(x.fi);
		fa[x.fi] = cur;
		son[cur].pb(x.fi);
	}
	vi now;
	for (auto x : son[cur])
	{
		dp[cur][0] += dp[x][0];
		dp[cur][1] += dp[x][0];
	} 
	for (auto x : E[cur])
	{
		if (fa[x.fi] == cur) now.pb(-(dp[x.fi][1] + x.se - dp[x.fi][0]));
	}
	sort(all(now));
	for (auto &x : now) x = max(0ll, -x); 
	F (i, min(k, (int)now.size())) dp[cur][0] += now[i];
	F (i, min(k - 1, (int)now.size())) dp[cur][1] += now[i];
}
 
void solve()
{
	int n;
	while (q --> 0)
	{
		cin >> n >> k;
		F1 (i, n) E[i].clear();
		F1 (i, n) son[i].clear();		
		F1 (i, n) fa[i] = 0;
		F1 (i, n) vis[i] = false;
		F1 (i, n - 1)
		{
			int x, y, z; cin >> x >> y >> z;
			E[x].pb(mp(y, z)); E[y].pb(mp(x, z));
		}
		F1 (i, n) dp[i][0] = dp[i][1] = 0;
		dfs(1);
		cout << max(dp[1][0], dp[1][1]) << '\n';
		//F1 (i, n) { dbgg(i); dbgg(dp[i][0]); dbg(dp[i][1]); }
	}
}
 
main()
{
	input();
	solve();
}