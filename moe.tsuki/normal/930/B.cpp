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

const int word = 34;
string s;
vi m[word];
int cnt[word];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
}

void solve()
{
	int n = s.length();
	s += s;
	F (i, n)
	{
		m[s[i] - 'a'].pb(i);
	}
	double res = 0;
	F (i, 26)
	{
		int ANS = 0;
		for (int shi = 0; shi < n; ++shi)
		{
			for (int pos : m[i])
			{
				++cnt[s[(pos + shi) % n] - 'a'];
			}
			int ans = 0;
			F (j, 26)
			{
				if (cnt[j] == 1)
					++ans;
			}
			for (int pos : m[i])
			{
				--cnt[s[(pos + shi) % n] - 'a'];
			}
			ANS = max(ANS, ans);
		}
		res += 1.0 * ANS / n;
	}
	cout << fixed << setprecision(10) << res << '\n';
}

main()
{
	input();
	solve();
}