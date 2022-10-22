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
int n, k;
int inv[123];
int a[123];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
}

int power(int a, int b)
{
	if (b == 0) return 1;
	if (b == 1) return a;
	int ret = power(a * a % mod, b / 2);
	if (b & 1) ret = ret * a % mod;
	return ret;
}

vector<pii> v;

void solve()
{
	int sqr = sqrt(n) + 5;
	for (int i = 2; i <= sqr; ++i)
	{
		int cur = 0;
		while (n % i == 0) ++cur, n /= i;
		if (cur != 0) v.pb(mp(i, cur));
	}
	if (n != 1) v.pb(mp(n, 1));
	int ans = 1;
	
	F1 (i, 100) inv[i] = power(i, mod - 2);
	
	for (auto x : v)
	{
		//dbg(x);
		F (i, x.se + 1) a[i] = 0;
		a[x.se] = 1;
		F (i, k) 
		{
			F (j, x.se + 1)
			{
				a[j] = a[j] * inv[j + 1] % mod;
				for (int k = j + 1; k <= x.se; ++k)
					a[j] = (a[j] + a[k] * inv[k + 1] % mod) % mod;
			}
		}
		int cur = 1;
		int now = 0;
		F (i, x.se + 1)
		{
			now = (now + a[i] * cur % mod) % mod;
			cur = cur * x.fi % mod;
		}
		ans = ans * now % mod;
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}