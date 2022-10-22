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
int x[maxn];
int n, m;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, m)
	{
		int a, b, c; cin >> a >> b >> c;
		x[a] -= c;
		x[b] += c;
	}
}

void solve()
{
	vi p, q;
	F1 (i, n) if (x[i] < 0) p.pb(i);
	F1 (i, n) if (x[i] > 0) q.pb(i);
	int ptr = 0;
	vector<pair<pii, int> > ans;
	for (auto k : p)
	{
		while (x[k] < 0)
		{
			int cur = min(x[q[ptr]], -x[k]);
			ans.pb(mp(mp(k, q[ptr]), cur));
			x[k] += cur;
			x[q[ptr]] -= cur;
			if (x[q[ptr]] == 0) ++ptr;
		}
	}
	cout << ans.size() << '\n';
	for (auto k : ans)
	{
		cout << k.fi.fi << ' ' << k.fi.se << ' ' << k.se << '\n';
	}
}

main()
{
	input();
	solve();
}