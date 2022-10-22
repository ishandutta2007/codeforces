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

const int maxn = 56789;
int n;
int app[maxn];

pair<pii, pii> x[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> x[i].fi.fi >> x[i].fi.se >> x[i].se.fi;
	F1 (i, n) x[i].se.se = i;
}

int dist(int i, int j)
{
	return abs(x[i].fi.fi - x[j].fi.fi)
				+abs(x[i].fi.se - x[j].fi.se)
				+abs(x[i].se.fi - x[j].se.fi);
}

void solve()
{
	vector<pair<int, pii> > v;
	F1 (i, n) F1 (j, n) if (i < j) v.pb(mp(dist(i, j), mp(i, j)));
	sort(all(v));
	for (auto x : v) if ((!app[x.se.fi]) && (!app[x.se.se]))
	{
		cout << x.se.fi << ' ' << x.se.se << '\n';
		app[x.se.fi] = app[x.se.se] = true;
	}
}

main()
{
	input();
	solve();
}