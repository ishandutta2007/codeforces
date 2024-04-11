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

const int maxn = 1234567, mod = 998244353;
int n, a[maxn], m[maxn], p[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	F1 (i, n) p[i] = (p[i - 1] + a[i]) % mod;
	m[0] = 1;
	F1 (i, n) m[i] = (m[i - 1] + m[i - 1]) % mod;
	int ans = 0;
	F1 (i, n - 1)
	{
		ans = (ans + (m[n - i] * p[i]) % mod) % mod;
		if (i != n - 1) 
			ans = (ans + ((m[n - i - 2] * (n - i - 1)) % mod * p[i]) % mod) % mod;
	}
	ans = (ans + p[n]) % mod;
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}