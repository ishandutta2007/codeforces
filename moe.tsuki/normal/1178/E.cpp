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

const int maxn = 1234567;
string s;
int n;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
}

vi v;
bool u[maxn];

void solve()
{
	n = s.length();
	s = '0' + s;
	for (int i = 1, j = n; i + 1 < j - 1; i += 2, j -= 2)
	{
		u[i] = u[i + 1] = u[j - 1] = u[j] = true;
		if (s[i] == s[j - 1])
		{
			v.pb(i);
			v.pb(j - 1);
			continue;
		}
		if (s[i] == s[j])
		{
			v.pb(i);
			v.pb(j);
			continue;
		}
		if (s[i + 1] == s[j - 1])
		{
			v.pb(i + 1);
			v.pb(j - 1);
			continue;
		}
		if (s[i + 1] == s[j])
		{
			v.pb(i + 1);
			v.pb(j);
			continue;
		}
	}
	F1 (i, n)
		if (!u[i])
		{
			v.pb(i); break;
		}
	sort(all(v));
	for (auto x : v) cout << s[x];
}

main()
{
	input();
	solve();
}