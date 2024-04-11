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

const int maxn = 123456, inf = 1000000007, mod = 998244353;
int n;
int val[maxn];
vector<pair<pii, int> > s, t;
int ans[maxn], ANS[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		s.pb(mp(mp(a, b), i));
		t.pb(mp(mp(c, d), i));
	}
}

void gao(vector<pair<pii, int> > v)
{
	F1 (i, n) ans[i] = 0;
	vector<pii> eve;
	// time inf add
	// time i query
	for (auto x : v)
	{
		eve.pb(mp(x.fi.se, inf + val[x.se]));
		eve.pb(mp(x.fi.fi, x.se));
	}
	sort(all(eve));
	int cur = 0;
	for (auto x : eve)
	{
		if (x.se >= inf) cur += x.se - inf;
		else ans[x.se] += cur;
	}
	eve.clear();
	
	for (auto x : v)
	{
		eve.pb(mp(-x.fi.fi, inf + val[x.se]));
		eve.pb(mp(-x.fi.se, x.se));
	}
	sort(all(eve));
	cur = 0;
	for (auto x : eve)
	{
		if (x.se >= inf) cur += x.se - inf;
		else ans[x.se] += cur;
	}
	
	F1 (i, n) ANS[i] ^= ans[i];
}

int myrand(int seed)
{
	F1 (i, 50) seed = (((seed << 27) + 123456789) % mod + mod) % mod;
	return seed;
}

void solve()
{
	srand(time(NULL));
	F1 (i, n) val[i] = myrand(rand());
//F1 (i, n) dbg(val[i]);
//F1 (i, 10000) dbg(myrand(rand()));
	gao(s);
	gao(t);
	bool ok = true;
	F1 (i, n) if (ANS[i]) ok = false;
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

main()
{
	input();
	solve();
}