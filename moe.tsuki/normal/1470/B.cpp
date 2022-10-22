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

const int maxn = 1234567;
int md[maxn];
int sf[maxn];
int a[maxn];
int t;
vi p;
map<int, int> m;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	for (int i = 2; i < maxn; ++i)
	{
		if (!md[i]) { p.pb(i); md[i] = i; }
		for (auto x : p)
		{
			if (x * i >= maxn) break;
			md[x * i] = x;
			if (i % x == 0) break;
		}
	}
	sf[1] = 1;
	for (int i = 2; i < maxn; ++i)
	{
		int x = md[i];
		int cnt = 0;
		int cur = i;
		while (cur % x == 0)
		{
			cur /= x;
			++cnt;
		}
		sf[i] = sf[cur];
		if (cnt & 1) sf[i] *= x;
	}
	//F1 (i, 100) { dbgg(i); dbg(sf[i]); }
	while (t --> 0)
	{
		m.clear();
		int n; cin >> n;
		F1 (i, n) 
		{
			cin >> a[i];
			a[i] = sf[a[i]];
			++m[a[i]];
		}
		int q; cin >> q;
		int d0 = 0;
		for (auto x : m) d0 = max(d0, x.se);
		int d1 = 0;
		int c0 = 0;
		//for (auto x : m) dbg(mp(x.fi, x.se));
		for (auto x : m)
		{
			if (x.fi == 1) c0 += x.se;
			else if (x.se & 1) d1 = max(d1, x.se);
			else c0 += x.se;
		}
		while (q --> 0)
		{
			int w; cin >> w;
			if (w == 0) cout << d0 << '\n';
			else cout << max(d1, c0) << '\n';
		}
	}
}

main()
{
	input();
	solve();
}