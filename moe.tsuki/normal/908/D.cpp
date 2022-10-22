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

const int mod = 1000000007;
const int maxn = 2345;
int k, a, b, p;
int DP[maxn][maxn], MK[maxn][maxn];
int ha;

int power(int x, int y)
{
	if (!y) return 1;
	int ret = power(x * x % mod, y / 2);
	if (y & 1) ret = (ret * x) % mod;
	return ret;
}

int inv(int x)
{
	return power(x % mod, mod - 2);
}

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> k >> a >> b;
	p = a * inv(a + b) % mod;
	ha = p * inv(1 - p) % mod;
	//dbg(p);
	//dbg(341 * inv(100) % mod);
}

int dp(int x, int y)
{
	
	if (MK[x][y]) return DP[x][y];
	MK[x][y] = 1;
	//dbg(inv(1-p)+mod);
	if (x + y >= k) return DP[x][y] = (x + y + ha) % mod;
	return DP[x][y] = ((p * dp(x + 1, y) % mod) + ((1 - p) * dp(x, y + x) % mod)) % mod; 
}

void solve()
{
	cout << (dp(1, 0) + mod) % mod << '\n';
}

main()
{
	input();
	solve();
}