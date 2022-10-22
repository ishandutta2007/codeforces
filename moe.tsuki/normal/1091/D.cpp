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

const int mod = 998244353;
const int maxn = 1234567;
int n;
int f[maxn], F[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
}

void solve()
{
	f[0] = 1;
	F1 (i, maxn - 1) f[i] = f[i - 1] * i % mod;
	if (n == 1) { cout << 1 << '\n'; return; }
	F[2] = 0;
	for (int i = 3; i <= n; ++i)
	{
		F[i] = f[i];
		F[i] = (F[i] + mod - i) % mod;
		F[i] = (F[i] + (i * F[i - 1] % mod)) % mod;
	}
	cout << (F[n] + f[n]) % mod << '\n';
}

main()
{
	input();
	solve();
}