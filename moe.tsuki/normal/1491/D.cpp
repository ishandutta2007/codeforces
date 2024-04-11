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

int q;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> q;
}

void solve()
{
	while (q --> 0)
	{
		int x, y; cin >> x >> y;
		if (__builtin_popcount(x) >= __builtin_popcount(y) && x <= y)
		{
			vi X, Y;
			bool ok = true;
			while (x) 
			{
				X.pb(x & (-x));
				x -= x & (-x);
			}
			while (y)
			{
				Y.pb(y & (-y));
				y -= y & (-y);
			}
			//dbgg(X);
			//dbg(Y);
			sort(all(X));
			sort(all(Y));
			int cur;
			for (int i = Y.size() - 1; i >= 0; --i)
			{
				cur = i;
				if (Y[i] == X[i]) ;
				else if (Y[i] < X[i]) ok = false;
				else break;
			}
			for (int i = 0; i < cur; ++i)
			{
				if (X[i] > Y[i]) ok = false;
			}
			if (ok) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}
}

main()
{
	input();
	solve();
}