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

int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		string s;
		int n;
		cin >> n;
		cin >> s;
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == 'b') cout << 'b';
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == 'u') cout << 'u';
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == 'g') cout << 'g';
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == 'y') cout << 'y';
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == 'r') cout << 'r';
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == 't') cout << 't';
		for (int i = 0; i < s.length(); ++i)
			if (s[i] != 'b' && s[i] != 'u' && s[i] != 'g'
			&& s[i] != 'y' && s[i] != 'r' && s[i] != 't') cout << s[i];
		cout << '\n';
	}
}

main()
{
	input();
	solve();
}