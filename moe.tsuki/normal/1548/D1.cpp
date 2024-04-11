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

const int maxn = 123456, mod = 1000000007;

#define fac_init() fact(maxn - 1, 1);
#define C(x,y) ((fact(x, 2) * fact(y, 3) % mod) * fact((x) - (y), 3) % mod)

int fact(int cur, int mode)
{
	static int f[maxn], g[maxn];
	if (mode == 1)
	{
		f[0] = 1;
		F1 (i, cur) f[i] = f[i - 1] * i % mod;
		g[cur] = 1;
		int a = f[cur], b = (mod - 2) << 1;
		while (b >>= 1)
		{
			if (b & 1) g[cur] = g[cur] * a % mod;
			a = a * a % mod;
		}
		for (int i = cur - 1; i >= 0; --i)
			g[i] = g[i + 1] * (i + 1) % mod;
		return 0;
	} else if (mode == 2) return f[cur];
	else return g[cur];
}

int n;
int x[maxn], y[maxn];
int u[2][2], cnt[2][2];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> x[i] >> y[i];
}

int gao(int x, int y)
{
	if (x == 0 && y == 0) return 0;
	return 1;
}

void solve()
{
	F1 (i, n) ++cnt[(x[i] / 2) & 1][(y[i] / 2) & 1];
	//F (j, 2) F (k, 2) dbg(cnt[j][k]); 
	int ans = 0;
	for (int i = 0; i < 64; ++i)
	{
		if (mp((i & 1) / 1, (i & 2) / 2) > mp((i & 4) / 4, (i & 8) / 8)
		 || mp((i & 4) / 4, (i & 8) / 8) > mp((i & 16) / 16, (i & 32) / 32)) continue;
		++u[(i & 1) / 1][(i & 2) / 2];
		++u[(i & 4) / 4][(i & 8) / 8];
		++u[(i & 16) / 16][(i & 32) / 32];
		int cur = 1;
		int ok = 0;
		ok ^= gao((i & 1) / 1 - (i & 4) / 4, (i & 2) / 2 - (i & 8) / 8);
		ok ^= gao((i & 1) / 1 - (i & 16) / 16, (i & 2) / 2 - (i & 32) / 32);
		ok ^= gao((i & 4) / 4 - (i & 16) / 16, (i & 8) / 8 - (i & 32) / 32);
		if (ok == 0) 
		{
			F (j, 2) F (k, 2)
				if (u[j][k] == 3) cur *= cnt[j][k] * (cnt[j][k] - 1) * (cnt[j][k] - 2) / 6;
				else if (u[j][k] == 2) cur *= cnt[j][k] * (cnt[j][k] - 1) / 2;
				else if (u[j][k] == 1) cur *= cnt[j][k]; 
		}
		else cur = 0;
		//dbg(cur); dbg(i);
		/*F (j, 2) F (k, 2) 
			if (u[j][k] == 3) cur /= 6;
			else if (u[j][k] == 2) cur /= 2;*/
		--u[(i & 1) / 1][(i & 2) / 2];
		--u[(i & 4) / 4][(i & 8) / 8];
		--u[(i & 16) / 16][(i & 32) / 32];
		ans += cur;
	} 
	cout << ans << '\n';
}

main()
{
	fac_init();
	input();
	solve();
}