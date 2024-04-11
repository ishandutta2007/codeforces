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
int n, m;
vi E[maxn];
int pa[maxn];
bool ok[maxn];
vi to;
vector<pii> edg;
int bye[maxn];
bool ad[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, m) 
	{
		int x, y; cin >> x >> y;
		E[x].pb(y); E[y].pb(x);
	}
}

int fr(int x)
{
	if (pa[x] == x) return x;
	return pa[x] = fr(pa[x]);
}

void solve()
{
	int mx = maxn;
	int big;
	F1 (i, n) 
	{
		if (mx > E[i].size())
			big = i, mx = E[i].size();
	}
	F1 (i, n) ok[i] = true;
	for (auto x : E[big]) ok[x] = false;
	F1 (i, n) if (!ok[i]) to.pb(i);
	
	map<pii, bool> F; 
	for (auto x : to)
		for (auto y : E[x]) if (!ok[y]) F[mp(x, y)] = F[mp(y, x)] = true;
	F1 (i, n) pa[i] = i;
	for (auto x : to)
		for (auto y : to)
			if (F.find(mp(x, y)) == F.end())
			{
				pa[fr(x)] = fr(y);
				//dbg(x); dbg(y);
			}
	// (i, n) dbg(fr(i));
	for (auto x : to)
	{
		F1 (i, n) ad[i] = false;
		for (auto y : E[x]) ad[y] = true;
		F1 (i, n) if (ad[i] == false && ok[i])
			bye[fr(x)] = 1;
	}
	int ans = 0;
	for (auto x : to)
	{
		if (!bye[fr(x)]) ++ans, ++bye[fr(x)];
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}