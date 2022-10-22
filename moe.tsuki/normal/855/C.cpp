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

const int mod = 1e9 + 7, maxx = 12, maxn = 123456;
int n, m, k, x;
int dp[maxn][maxx][3];
vi E[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, n - 1)
	{
		int a, b; cin >> a >> b;
		E[a].pb(b); E[b].pb(a);
	}
	cin >> k >> x;
}



void dfs(int cur, int fa)
{
	for (int i : E[cur]) if (i != fa)
		dfs(i, cur);
	
	int p[maxx], p1[maxx]; // mul_all_child_0
	{
		for (int i = 1; i < maxx; ++i) p[i] = 0;
		p[0] = 1;
		
		
		
		for (int i : E[cur])
		{

			for (int j = 0; j < maxx; ++j) p1[j] = 0;
			if (i != fa)
			{
				for (int j = 0; j < maxx; ++j)
				{
					for (int k = 0; k < maxx; ++k)
						if (j + k < maxx)
							p1[j + k] = (p1[j + k] + p[j] * dp[i][k][0] % mod) % mod;
				}
				for (int j = 0; j < maxx; ++j) p[j] = p1[j];
			}
			
			
		}
	}
	
	int q[maxx], q1[maxx];
	{
		for (int i = 1; i < maxx; ++i) q[i] = 0;
		q[0] = 1;
		for (int i : E[cur])
		{
			for (int j = 0; j < maxx; ++j) q1[j] = 0;
			if (i != fa)
			{
				for (int j = 0; j < maxx; ++j)
				{
					for (int k = 0; k < maxx; ++k)
						if (j + k < maxx)
							q1[j + k] = (q1[j + k] + q[j] * (dp[i][k][0] + dp[i][k][1] + dp[i][k][2]) % mod) % mod;
				}
				for (int j = 0; j < maxx; ++j) q[j] = q1[j];
			}
			
			
		}
	}
	
	
	int r[maxx], r1[maxx];
	{
		for (int i = 1; i < maxx; ++i) r[i] = 0;
		r[0] = 1;
		for (int i : E[cur])
		{
			for (int j = 0; j < maxx; ++j) r1[j] = 0;
			if (i != fa)
			{
				for (int j = 0; j < maxx; ++j)
				{
					for (int k = 0; k < maxx; ++k)
						if (j + k < maxx)
							r1[j + k] = (r1[j + k] + r[j] * (dp[i][k][0] + dp[i][k][1]) % mod) % mod;
				}
				for (int j = 0; j < maxx; ++j) r[j] = r1[j];
			}
			
			
		}
	}
	
	//for (int j = 0; j < maxx; ++j) cout << p[j] << ' '; cout << '\n';
	//for (int j = 0; j < maxx; ++j) cout << q[j] << ' '; cout << '\n';
		
	for (int i = 1; i <= x; ++i)
	{
		dp[cur][i][2] = p[i - 1]; 
		dp[cur][i][0] = q[i] * (k - 1) % mod;
		
		dp[cur][i][1] = r[i] * (m - k) % mod;
	}
	dp[cur][0][0] = (k - 1) * q[0] % mod;
	dp[cur][0][1] = (m - k) * q[0] % mod;
}

void solve()
{
	dfs(1, 1);
	//dbg(dp[1][1][0]);
	//dbg(dp[1][1][1]);
	//dbg(dp[1][0][1]);
	//dbg(dp[1][0][0]);
	int ans = 0;
	for (int i = 0; i <= x; ++i) ans = (ans + dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) % mod;
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}