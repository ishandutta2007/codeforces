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

const int oo = 1e11, maxn = 123456;
int n, k, ma = -oo, mi = oo;
int premi[maxn], sufmi[maxn];
vi v;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int t;
	for (int i = 0; i < n; ++i) 
	{ 
		cin >> t; v.pb(t);
		mineq(mi, t); 
		maxeq(ma, t);
	}
}

void solve()
{
	if (k == 1) cout << mi << '\n';
	else if (k == 2)
	{
		int ans = -oo;
		premi[0] = v[0];
		for (int i = 1; i < n; ++i)
			premi[i] = min(premi[i - 1], v[i]);
		sufmi[n - 1] = v[n - 1];
		for (int i = n - 2; i >= 0; --i)
			sufmi[i] = min(sufmi[i + 1], v[i]);
		for (int i = 0; i < n - 1; ++i)
		{
			maxeq(ans, max(premi[i], sufmi[i + 1]));
		}
		cout << ans << '\n';
	}
	else cout << ma << '\n';
}

main()
{
	input();
	solve();
}