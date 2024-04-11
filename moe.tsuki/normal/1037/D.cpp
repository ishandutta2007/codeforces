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
int n;
vector<int> E[maxn];
int ord[maxn];
vector<pii> son[maxn];
int ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int x, y;
	F1 (i, n - 1) 
	{
		cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
	F1 (i, n) cin >> ord[i];
}

map<int, int> id;

void dfs(int cur, int par)
{
	for (int x : E[cur])
	{
		if (x != par)
		{
			son[cur].pb(mp(id[x], x));
			dfs(x, cur);
		}
	}
	sort(all(son[cur]));
}

void solve()
{
	F1 (i, n) id[ord[i]] = i;
	dfs(ord[1], 0);
	queue<int> q;
	q.push(ord[1]);
	int cnt = 0;
	while (q.size())
	{
		int cur = q.front(); q.pop();
		ans[++cnt] = cur;
		for (auto x : son[cur])
		{
			q.push(x.se);
		}
	}
	int ok = true;
	if (ord[1] != 1) ok = false;
	F1 (i, n) if (ord[i] != ans[i]) ok = false;
	if (ok) cout << "Yes\n";
	else cout << "No\n";
}

main()
{
	input();
	solve();
}