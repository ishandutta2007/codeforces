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
int T;
set<pii> s, t;
int in[maxn], out[maxn];
int ans;
vi E[maxn], F[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
}

void dfs(int cur)
{
	pii del = mp(0, 0);
	auto x = s.lower_bound(mp(in[cur], 0));
	bool fu = false;
	if (x != s.end() && x -> se < out[cur])
	{
		fu = true;
	} else
	{
		s.insert(mp(in[cur], out[cur]));
		auto y = t.lower_bound(mp(out[cur], 0));
		//dbg(*y);
		t.insert(mp(out[cur], in[cur]));
		if (y != t.end() && y -> se < in[cur])
		{
			del = *y;
			t.erase(y);
			s.erase(mp(del.se, del.fi));
		}
		ans = max(ans, (int) s.size());
	}
	/*dbg(cur);
	for (auto x : s) dbg(x);
	dbg("");
	for (auto x : t) dbg(x);
	dbg("");*/
	for (auto x : E[cur])
		dfs(x);
	if (del.fi) 
	{
		s.insert(mp(del.se, del.fi));
		t.insert(del);
	}
	if (!fu)
	{
		s.erase(mp(in[cur], out[cur]));
		t.erase(mp(out[cur], in[cur]));
	}
}

int cnt;

void dfso(int cur)
{
	in[cur] = ++cnt;
	for (auto x : F[cur])
		dfso(x);
	out[cur] = ++cnt;
}

void solve()
{
	while (T --> 0)
	{
		int n; cin >> n;
		F1 (i, n) E[i].clear();
		F1 (i, n) F[i].clear();
		F1 (i, n - 1)
		{
			int x;
			cin >> x;
			E[x].pb(i + 1);
		}
		F1 (i, n - 1)
		{
			int x; cin >> x;
			F[x].pb(i + 1);
		}
		// F1 (i, n) vis[i] = false;
		cnt = 0;
		dfso(1);
		// F1 (i, n) vis[i] = false;
		//F1 (i, n) dbg(mp(in[i], out[i]));
		s.clear(); t.clear();
		ans = 0;
		dfs(1);
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}