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
int n, k;
vi E[maxn];
int sz[maxn];
int up[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	F1 (i, n - 1)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

void dfs(int cur)
{
	sz[cur] = 1;
	for (auto x : E[cur]) if (!sz[x])
	{
		up[x] = up[cur] + 1;
		dfs(x);
		sz[cur] += sz[x];
	}
}

void solve()
{
	dfs(1);
	vi v;
	F1 (i, n) v.pb(sz[i] - 1 - up[i]);
	sort(all(v));
	int ans = 0;
	for (int i = n - 1; i + 1 >= k + 1; --i)
		ans += v[i];
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}