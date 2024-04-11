#pragma GCC optimize("Ofast,no-stack-protector")
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
#define MEOW { cout << "meowwwww" << '\n'; system("pause"); }
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

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

const int maxn = 234567, mod = 1000000007;

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

int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

int pre[maxn];
int bit[maxn];

#define lowbit(x) (x & (-x))

void add(int x)
{
	++x;
	while (x < maxn) 
	{
		bit[x]++;
		x += lowbit(x);
	}
}

int qry(int x)
{
	++x;
	int r = 0;
	while (x)
	{
		r += bit[x];
		x -= lowbit(x);
	}
	return r;
}

vi pos[maxn];
int ans;

void gao(int l, int r)
{
	//dbg(mp(l, r));
	if (l >= r - 2) return;
	//if (l >= 0) 
	++ans;
	auto x = lower_bound(all(pos[pre[l + 1]]), l + 2);
	if (x == pos[pre[l + 1]].end()) return;
	//else dbg(*x);
	int last = l + 1;
	while (*x <= r)
	{
		gao(last, (*x));
		last = *x;
		if (x == pos[pre[l + 1]].end()) break;
		++x;
	}
}

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		string s; cin >> s;
		F1 (i, n + n)
		{
			pre[i] = pre[i - 1];
			if (s[i - 1] == '(') ++pre[i];
			else --pre[i];
		}
		pre[n + n + 1] = 1;
		ans = 0;
		//F (i, n + n + 1) bit[i] = 0;
		F (i, n + n + 1) pos[i].clear();
		F (i, n + n + 1) //if (i > 0 && s[i - 1] == '(') 
			pos[pre[i]].pb(i);
		//pos[1].pb(n + n + 1);
		
		gao(-1, n + n + 1);
		/*int ans = 0;
		F (i, n + n + 1)
		{
			bool f = true;
			int last = 0;
			//if (pos[i].size() >= 2) ++ans;
			if (pos[i].size()) ++ans;
			for (auto x : pos[i])
			{
				if (!f)
				{
					if (qry(x - 1) - qry(last) != 0) ++ans; 
				}
				last = x;
				add(x);
				f = false;
			}
		}
		--ans;*/
		cout << ans << '\n';
	}
}

main()
{
	fac_init();
	input();
	solve();
}