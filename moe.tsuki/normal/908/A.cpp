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

int n;
string s;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
}

void solve()
{
	n = s.length();
	int ans = 0;
	map<char, int> app;
	app['1'] = 1;
	app['3'] = 1;
	app['5'] = 1;
	app['7'] = 1;
	app['9'] = 1;
	app['a'] = 1;
	app['e'] = 1;
	app['i'] = 1;
	app['o'] = 1;
	app['u'] = 1;
	F (i, n) if (app[s[i]]) ++ans;
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}