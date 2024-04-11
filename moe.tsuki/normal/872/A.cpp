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
int n, m;
int a[123], b[123], app[123];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) app[a[i]] = true;
	for (int i = 0; i < m; ++i) cin >> b[i];
	int ans = oo;
	for (int i = 0; i < m; ++i) if (app[b[i]]) mineq(ans, b[i]);
	if (ans == oo) 
	{
		int p = oo, q = oo;
		for (int i = 0; i < n; ++i) mineq(p, a[i]);
		for (int i = 0; i < m; ++i) mineq(q, b[i]);
		ans = 10 * min(p, q) + max(p, q);
	}	
	cout << ans << '\n';
}

void solve()
{

}

main()
{
	input();
	solve();
}