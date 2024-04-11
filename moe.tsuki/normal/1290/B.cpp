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

const int maxn = 234567;
int q;
string s;
int pre[26][maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	cin >> q;
}

void solve()
{
	int n = s.length();
	F (i, n) ++pre[s[i] - 'a'][i + 1];
	F (i, 26) F1 (j, maxn - 1)
		pre[i][j] += pre[i][j - 1];
	while (q --> 0)
	{
		int l, r; cin >> l >> r;
		if (l == r)
			cout << "Yes\n";
		else
		{
			int cnt = 0;
			F (i, 26) if (pre[i][r] - pre[i][l - 1]) ++cnt;
			if (cnt >= 3)
				cout << "Yes\n";
			else if (s[l - 1] == s[r - 1])
				cout << "No\n";
			else cout << "Yes\n";
		}
	}
}

main()
{
	input();
	solve();
}