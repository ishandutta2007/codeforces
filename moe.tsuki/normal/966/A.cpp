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

const int oo = 1e9;
int n, m, e, s, v;
vi E, K;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> s >> e >> v;
	int x;
	F1 (i, s) 
	{
		cin >> x;
		K.pb(x);
	}
	F1 (i, e)
	{
		cin >> x;
		E.pb(x);
	}
	//cout << E;
	//cout << K;
}

int fu1(int b, int d)
{
	// stair
	int ans = oo;
	if (s == 0) return ans;
	if (lower_bound(all(K), b) != lower_bound(all(K), d)) return d - b;
	auto x = lower_bound(all(K), b);
	if (x != K.begin()) 
	{
		--x;
		ans = min(ans, d - b + (b - *x) + (b - *x));
	}
	x = lower_bound(all(K), d);
	if (x != K.end())
	{
		ans = min(ans, d - b + (*x - d) + (*x - d));
	}
	return ans;
}

int fu2(int b, int d)
{
	// elevator
	int ans = oo;
	if (e == 0) return ans;
	if (lower_bound(all(E), b) != lower_bound(all(E), d)) return d - b;
	auto x = lower_bound(all(E), b);
	if (x != E.begin()) 
	{
		--x;
		ans = min(ans, d - b + (b - *x) + (b - *x));
	}
	x = lower_bound(all(E), d);
	if (x != E.end())
	{
		ans = min(ans, d - b + (*x - d) + (*x - d));
	}
	return ans;
}

void solve()
{
	int q; cin >> q;
	while (q --> 0)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int h = abs(c - a);
		//dbg(h);
		int ans = oo;
		//dbg(ans);
		if (d < b) swap(b, d);
		ans = min(ans, fu1(b, d) + h);
		//dbg("dis elev");
		//dbg(ans);
		ans = min(ans, fu2(b, d) + (h + v - 1) / v);
		//dbg(ans);
		if (h == 0) ans = d - b;
		cout << ans << '\n'; 
	}
}

main()
{
	input();
	solve();
}