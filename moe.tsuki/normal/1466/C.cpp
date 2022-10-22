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

int dp[123456][4];

void solve()
{
	while (t --> 0)
	{
		string s; cin >> s;
		int n = s.length();
		F (i, n + 1)
			F (j, 4)
				dp[i][j] = 123456789;
		dp[0][0] = 0;
		F1 (i, n)
			F (j, 4)
			{
				int a = j / 2;
				int b = j & 1;
				int c = 0;
				if (i > 2 && s[i - 1] == s[i - 3])
				{
					if (b == 0)
						c = 1; 
				}
				if (i > 1 && s[i - 1] == s[i - 2])
					if (a == 0 && b == 0) continue;
				for (int d = 0; d <= 1; ++d)
				{
					if (c == 1 && d == 0) continue;
					dp[i][j] = min(dp[i][j], dp[i - 1][d * 2 + a] + b);
					//dbgg(mp(i - 1, d * 2 + a));
					//dbg(mp(i, j));
				}
			}
		cout << min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])) << '\n';
	}
}

main()
{
	input();
	solve();
}