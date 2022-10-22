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

const int maxn = 123456, mod = 1000000007, zog = 18;
int n; 
int a[maxn];
vi E[maxn];
int dep[maxn];
int fa[maxn][zog];
int g[maxn][zog];
int ans;
int wei[maxn];

void dfs(int cur)
{
	//in[cur] = ++tim;
	for (auto x : E[cur])
		if (!dep[x])
		{
			dep[x] = dep[cur] + 1;
			fa[x][0] = cur;
			dfs(x);
			if (a[x] == 0) wei[cur] += wei[x];
		}
	//out[cur] = tim;
}

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
	F1 (i, n - 1)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

void gao(int cur, int step, int num, int wei)
{
	
	//dbgg(cur); dbgg(step); dbg(num);
	if (step == 0) 
	{
		ans = (ans + __gcd(g[cur][0], num) * wei % mod) % mod; return;
	}
	if (num != 0 && g[cur][step] % num == 0)
	{
		//dbgg(cur); dbgg(step); dbgg(cur); dbgg(dep[cur]); dbgg(fa[cur][step]); dbg(dep[fa[cur][step]]);
		assert(dep[cur] >= dep[fa[cur][step]]);
		ans = (ans + ((dep[cur] - dep[fa[cur][step]]) * num % mod) * wei % mod) % mod;
		//if (1 << (step) < dep[cur]) gao(fa[cur][step], step - 1, num, wei);
	} else
	{
		gao(cur, step - 1, num, wei);
		if ((1 << (step - 1)) < dep[cur]) gao(fa[cur][step - 1], step - 1, __gcd(num, g[cur][step - 1]), wei);
	}
}

void solve()
{
	fa[1][0] = 0;
	dep[1] = 1;
	F1 (i, n) wei[i] = 1;
	dfs(1);
	for (int j = 1; j < zog; ++j)
		F1 (i, n)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	F1 (i, n) g[i][0] = a[i];
	for (int j = 1; j < zog; ++j)
		F1 (i, n) g[i][j] = __gcd(g[i][j - 1], g[fa[i][j - 1]][j - 1]);
	F1 (i, n)
	{
		if (a[i] != 0)
			gao(i, zog - 1, a[i], wei[i]);
		//dbg(ans);
	}
	ans %= mod; ans += mod; ans %= mod;
	cout << ans << '\n';
	//F1 (i, n) dbg(wei[i]);
}

main()
{
	input();
	solve();
}