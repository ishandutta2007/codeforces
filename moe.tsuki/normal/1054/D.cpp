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
int n, k;
int a[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	F1 (i, n) cin >> a[i];
}

void solve()
{	
	int ans = n * (n + 1) / 2;
	int one = (1 << k) - 1;
	F1 (i, n) a[i] ^= a[i - 1];
	map<int, int> app;
	F1 (i, n)
	{
		if ((a[i] ^ one) < a[i]) a[i] = a[i] ^ one;
		++app[a[i]];
	}
	++app[0];
	for (auto x : app)
	{
		int cur = x.se;
		int p = cur / 2;
		int q = (cur + 1) / 2;
		ans -= p * (p - 1) / 2 + q * (q - 1) / 2;
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}