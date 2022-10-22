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

const int mod = 998244353, maxn = 5678;
int a, b, c, frac[maxn], inv[maxn];


void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c;
}

int power(int a, int p)
{
	if (p == 0) return 1;
	if (p == 1) return a;
	int ret = power(a, p >> 1);
	ret = ret * ret % mod;
	if (p & 1) ret = ret * a % mod;
	return ret;  
}

int gao(int a, int b)
{
	//dbg(inv[0]);
	int ret = 0;
	for (int k = 0; k <= min(a, b); ++k)
	{
		if (k == 0) ret += 1;	
		else ret += (((frac[a] * inv[k] % mod) * inv[a - k] % mod) * frac[b] % mod) * inv[b - k] % mod;
		//dbg(ret);
		//C(a, k) * P(b, a);
	}
	return ret % mod;
}

void solve()
{
	frac[0] = 1;
	for (int i = 1; i < maxn; ++i) frac[i] = frac[i - 1] * i % mod;
	inv[maxn - 1] = power(frac[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; --i)
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
	int ans = 1;
	ans = ans * gao(a, b) % mod;
	ans = ans * gao(b, c) % mod;
	ans = ans * gao(c, a) % mod;
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}