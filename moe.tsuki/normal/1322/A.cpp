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
	cin >> n;
	cin >> s;
}

void solve()
{
	int cur = 0;
	int last = 0;
	int ans = 0;
	F1 (i, n)
	{
		if (s[i - 1] == '(') ++cur;
		else --cur;
		if (cur == 0 && last > 0)
		{
			ans += i - last + 1;
			last = 0;
		}
		if (cur < 0 && last == 0)
			last = i;
	}
	if (cur == 0) cout << ans << '\n';
	else cout << "-1\n";
}

main()
{
	input();
	solve();
}