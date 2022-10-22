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
int x[234567];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n, k; cin >> n >> k;
		F1 (i, n) cin >> x[i];
		for (int i = n; i >= 1; --i) x[i] -= x[i - 1];
		int cur = 0;
		F1 (i, n - 1) cur = __gcd(cur, x[i + 1]);
		if (cur == 0)
		{
			if ((k - x[1]) == 0) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		//dbg(cur);
		//F1 (i, n - 1) dbg(x[i + 1]);
		if ((k - x[1]) % abs(cur) == 0)
			cout << "YES\n";
		else cout << "NO\n";
	}
}

main()
{
	input();
	solve();
}