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

const int maxn = 1234567, mod = 1000000007;
int n;
int a[maxn];
vector<int> E[maxn];
vector<pii> F[maxn];
bool vis[maxn];
bool used[maxn];
int fu[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) 
		cin >> a[i + i - 1] >> a[i + i];
}

stack<int> stk;

void euler(int cur)
{
	for (int i = fu[cur]; i < F[cur].size(); i = fu[cur])
	{
		int e = F[cur][i].se;
		fu[cur] = i + 1;
		if (!used[e / 2])
		{
			used[e / 2] = true;
	    euler(F[cur][i].fi);
	    stk.push(e);
	  }
  }
}

void dfs(int cur)
{
	vis[cur] = true;
	for (auto x : E[cur]) if (!vis[x]) dfs(x);
}

bool ok(int t)
{
	int cur = 1 << t;
	F (i, cur) E[i].clear();
	F1 (i, n) 
	{
		E[a[i + i - 1] & (cur - 1)].pb(a[i + i] & (cur - 1));
		E[a[i + i] & (cur - 1)].pb(a[i + i - 1] & (cur - 1));
	}
	bool fu = true;
	F (i, cur) vis[i] = false;
	int com = 0;
	F (i, cur)
	{
		if (!vis[i]) if (E[i].size() != 0) { dfs(i); ++com; }
	}
	if (com > 1) fu = false;
	F (i, cur) if (E[i].size() & 1) fu = false;
// connect
	return fu;
}

void solve()
{
	int d = 32; int an = 0;
	while (d >>= 1)
		if (an + d <= 20 && ok(an + d)) an += d; 
	if (an == 0)
	{
		cout << "0\n";
		F1 (i, n + n) cout << i << ' ';
	} else
	{
		cout << an << '\n';
		int cur = 1 << an;
		F1 (i, n) 
		{
			F[a[i + i - 1] & (cur - 1)].pb(mp(a[i + i] & (cur - 1), i * 2));
			F[a[i + i] & (cur - 1)].pb(mp(a[i + i - 1] & (cur - 1), i * 2 + 1));
		}
		
		euler(a[1] & (cur - 1));
		while (!stk.empty()) 
		{
	    cur = stk.top();
			stk.pop();
			if (cur & 1) cout << cur - 1 << ' ' << cur - 2 << ' ';
			else cout << cur - 1 << ' ' << cur << ' ';
	  }
	}
}

main()
{
	input();
	solve();
}