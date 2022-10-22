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

const int maxn = 567890, mod = 1000000007;
int n, m;

vector<pair<pii, int> > v;
int pa[maxn + 1];
int po[maxn];
int app[maxn + 1];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, n)
	{
		int x, y, z;
		cin >> x;
		cin >> y; z = maxn;
		if (x == 2) cin >> z;
		if (y > z)
			swap(y, z);
		v.pb(mp(mp(y, z), i));
	}
}

int root(int x)
{
	if (pa[x] == x) return x;
	return pa[x] = root(pa[x]);
}

void solve()
{
	po[0] = 1;
	F1 (i, n)
		po[i] = po[i - 1] * 2 % mod;
	vi ans;
	F1 (i, m) pa[i] = i;
	for (auto x : v)
		if (root(x.fi.fi) != root(x.fi.se))
		{
			pa[root(x.fi.fi)] = root(x.fi.se);
			ans.pb(x.se);
		}
	cout << po[ans.size()] << ' ' << ans.size() << '\n';
	for (auto x : ans) cout << x << ' ';
}

main()
{
	input();
	solve();
}