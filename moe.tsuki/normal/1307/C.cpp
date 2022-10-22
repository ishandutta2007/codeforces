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

string s;
int cnt[34];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
}

void solve()
{
	int n = s.length();
	F (i, n) ++cnt[s[i] - 'a' + 1];
	int ans = 0;
	F1 (i, 26)
	{
		F1 (j, 26)
		{
			if (i == j) ans = max(ans, max(cnt[i], cnt[i] * (cnt[i] - 1) / 2));
			else 
			{
				int now = 0, cur = 0;
				F (k, n)
				{
					if (s[k] - 'a' + 1 == i) ++cur;
					else if (s[k] - 'a' + 1 == j) now += cur;
				}
				ans = max(ans, now);
			}
		}
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}