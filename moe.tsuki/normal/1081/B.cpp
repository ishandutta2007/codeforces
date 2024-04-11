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
int n;
int a[maxn];
int ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	map<int, int> m;
	map<int, vi> v;
	F1 (i, n) a[i] = n - a[i];
	F1 (i, n) ++m[a[i]];
	for (auto x : m) if (x.se % x.fi) { cout << "Impossible\n"; return; }
	cout << "Possible\n";
	//int cnt = 0;
	//F1 (i, n) if (!app[a[i]]) app[a[i]] = ++cnt;
	F1 (i, n) v[a[i]].pb(i);
	int last = 0;
	for (auto x : v)
	{
		int mod = x.fi;
		int cur = 0;
		for (int y : x.se)
		{
			if (cur == 0) ++last;
			ans[y] = last;
			cur = (cur + 1) % mod;
		}
	}
	F1 (i, n) cout << ans[i] << ' ';
}

main()
{
	input();
	solve();
}