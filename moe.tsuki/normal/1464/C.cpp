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

int n, t;
string s;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> t;
	cin >> s;
}

int fu(char x)
{
	return 1 << (x - 'a');
}

void solve()
{
	t -= fu(s[n - 1]);
	t += fu(s[n - 2]);
	int lo = 123;
	int cur = 0;
	F (i, n - 2) lo = min(lo, (int) s[i] - 'a');
	F (i, n - 2) cur += fu(s[i]);
	if (lo == 123)
	{
		if (t == 0) cout << "Yes\n";
		else cout << "No\n";
		return;
	}
	if ((cur - t) * (-cur - t) <= 0)
	{
		if ((t - cur) % (1 << (lo + 1)) == 0)
			cout << "Yes\n";
		else cout << "No\n";
	} else cout << "No\n";
}

main()
{
	input();
	solve();
}