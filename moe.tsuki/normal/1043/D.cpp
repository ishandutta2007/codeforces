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

const int maxn = 123456, maxk = 11;
int n, k;

int a[maxk][maxn];
int app[maxk][maxn];
int hsh[maxk][maxn];
int power[maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int base, mod;

void input()
{
	base = rng() % 1234567891;
	mod = rng() % 1234567891;
	//dbg(base); dbg(mod);

	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	F1 (i, k) F1 (j, n) 
	{
		cin >> a[i][j];
		app[i][a[i][j]] = j;
	}
}

void gao(int cur)
{
	F1 (i, n) 
	{
		hsh[cur][i] = (hsh[cur][i - 1] * base + a[cur][i]) % mod;
	}
}

int geth(int cur, int l, int r)
{
	int ret = (hsh[cur][r] - hsh[cur][l - 1] * power[r - l + 1]) % mod;
	ret = (ret + mod) % mod;
	return ret;
}

bool match(int l, int r)
{
	int cur = geth(1, l, r);
	for (int i = 2; i <= k; ++i)
	{
		int start = app[i][a[1][l]];
		if (start + r - l > n || 
			geth(i, start, start + r - l) != cur) return false;
	}
	return true;
}

void solve()
{
	power[0] = 1;
	F1 (i, n) power[i] = power[i - 1] * base % mod;
	F1 (i, k) gao(i);
	
	int cur = 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		while (cur <= n && match(i, cur)) ++cur;
		--cur;
		ans += cur - i + 1;
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}