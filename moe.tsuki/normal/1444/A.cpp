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

const int maxn = 123456;
int sie[maxn];
int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

vi v;

void solve()
{
	for (int i = 2; i < maxn; ++i)
	{
		if (!sie[i])
		{
			v.pb(i);
			for (int j = i + i; j < maxn; j += i)
				sie[j] = true;
		}
	}
	while (t --> 0)
	{
		int ans = 1234567891123456789ll;
		int x, y; cin >> x >> y;
		int xx = x;
		if (x % y) 
		{
			cout << x << '\n';
			continue;
		}
		for (auto p : v)
		{
			int xp = 0, yp = 0;
			while (y % p == 0)
			{
				y /= p;
				++yp;
			}
			while (x % p == 0)
			{
				x /= p;
				++xp;				
			}
			if (yp > 0)
			{
				int cur = 1;
				F (i, xp - yp + 1)
					cur *= p;
				ans = min(ans, cur);
			}
		}
		if (y != 1)
		{
			int xp = 0, yp = 1;
			while (x % y == 0)
			{
				x /= y;
				++xp;				
			}
			int cur = 1;
			F (i, xp - yp + 1)
				cur *= y;
			ans = min(ans, cur);
		}
		cout << xx / ans << '\n';
	}
}

main()
{
	input();
	solve();
}