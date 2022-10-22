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

const int maxn = 567890, base = 353, mod = 1234567891;
int t;
int c[maxn];
int val[maxn], hsh[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n, m;
		cin >> n >> m;
		F1 (i, n) cin >> c[i];
		val[0] = 1;
		F1 (i, n) 
			val[i] = (val[i - 1] * base + 227) % mod;
		F1 (i, n) hsh[i] = 0;
		F1 (i, m)
		{
			int u, v;
			cin >> u >> v;
			hsh[v] ^= val[u]; 
		}
		map<int, int> ma;
		F1 (i, n) ma[hsh[i]] += c[i];
		int ans = 0;
		for (auto x : ma)
		{
			if (x.fi != 0)
				ans = __gcd(ans, x.se);
			//dbg(x.fi); dbg(x.se);
		}
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}