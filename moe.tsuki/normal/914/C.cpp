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

const int maxn = 1234, mod = 1000000007;
string s;
int tim, fac[maxn], inv[maxn], t[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	cin >> tim;
}

int power(int a, int b)
{
	if (a == 0) return 0;
	if (b == 0) return 1;
	int ret = power(a * a % mod, b >> 1);
	if (b & 1) ret = (ret * a) % mod;
	return ret;
}

int C(int a, int b)
{
	// dbgg(a); dbg(b);
	return ((fac[a] * inv[b]) % mod * inv[a - b]) % mod;
}

void solve()
{
	int ans = 0;
	fac[0] = inv[0] = 1;
	F1 (i, maxn - 1) fac[i] = (fac[i - 1] * i) % mod; 
	F1 (i, maxn - 1) inv[i] = power(fac[i], mod - 2); 
	t[0] = 1234567;
	F1 (i, maxn - 1)
	{
		int j = i;
		while (j != 1)
		{
			++t[i];
			int k = 0;
			while (j)
			{
				if (j & 1) ++k;
				j >>= 1;
			}
			j = k;
		}
		// dbgg(i); dbg(t[i]); MEOW;
	}
	int cnt = 0;
	F (i, s.length())
	{
		// dbg(s[i]);
		if (s[i] == '1')
		{
			for (int j = 0; j <= s.length() - 1 - i; ++j)
			{
				if (t[cnt + j] + 1 == tim) 
				{
					ans = (ans + C(s.length() - 1 - i, j)) % mod; 
				}
			}
			++cnt;
		}
	}
	if (t[cnt] + 1 == tim) ans = (ans + 1) % mod;
	if (tim == 1) ans = (ans + mod - 1) % mod;
	if (tim == 0) ans = (ans + 1) % mod;
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}