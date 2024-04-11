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

const int maxn = 123;
int x0, y0, ax, ay, bx, by;
int xs, ys, t;
int x[maxn], y[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
}

void solve()
{
	int cur = 0;
	x[0] = x0, y[0] = y0;
	while (true)
	{
		if (x[cur] > 10000000000000000ll) break;
		if (y[cur] > 10000000000000000ll) break;
		++cur;
		x[cur] = ax * x[cur - 1] + bx;
		y[cur] = ay * y[cur - 1] + by;
	}
	int ans = 0;
	for (int i = 0; i <= cur; ++i)
	{
		for (int j = i; j <= cur; ++j)
			for (int k = 0; k <= i; ++k)
			{
				if (abs(x[i] - xs) + abs(y[i] - ys)
				  + x[j] - x[k] + y[j] - y[k]
				  + min(abs(x[i] - x[j]) + abs(y[i] - y[j])
					    , abs(x[i] - x[k]) + abs(y[i] - y[k])) <= t)
					ans = max(ans, j - k + 1);
			}
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}