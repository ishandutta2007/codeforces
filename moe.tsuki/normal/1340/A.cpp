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
int t;
int a[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		int cur = 1;
		a[n + 1] = 0;
		vi pos;
		F1 (i, n)
		{
			if (a[i + 1] < a[i])
				pos.pb(i + 1);
		}
		bool ok = true;
		int last = 1;
		int mn = n + 1;
		for (auto x : pos)
		{
			// last ~ x - 1
			for (int i = last; i <= x - 2; ++i)
			{
				if (a[i] != a[i + 1] - 1) ok = false;
			}
			if (mn != a[x - 1] + 1) ok = false;
			mn = a[last]; 
			last = x;
		}
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
}

main()
{
	input();
	solve();
}