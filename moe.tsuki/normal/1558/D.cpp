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

const int maxn = 456789, mod = 998244353;

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

struct treap
{
	treap *lc, *rc;
	int size;
	int tag, val;
	treap(int v)
	{
		lc = rc = NULL;
		size = 1;
		tag = 0;
		val = v; 
	}
};

int myrand()
{
	static int x = 1234567451234567ll;
	return x = (x ^ (x << 3)) % 998244353;
}

#define sz(x) ((x) ? (x -> size) : 0)

void push(treap *t)
{
	t -> val += t -> tag;
	if (t -> lc) t -> lc -> tag += t -> tag;
	if (t -> rc) t -> rc -> tag += t -> tag; 
	t -> tag = 0;
} 

void pull(treap *t)
{
	if (!t) return;
	t -> size = 1 + sz(t -> lc) + sz(t -> rc);
}

treap *merge(treap *a, treap *b)
{
	if (!a) return b;
	if (!b) return a;
	push(a); push(b);
	assert(a -> val < b -> val);
	treap *t;
	if (myrand() % (sz(a) + sz(b)) < sz(a))
	{
		t = a;
		//b -> tag -= a -> tag;
		t -> rc = merge(t -> rc, b);
	} else
	{
		t = b;
		//a -> tag -= b -> tag;
		t -> lc = merge(a, t -> lc);
	}
	pull(t);
	return t;
}

void split(treap *t, int v, treap* &a, treap* &b)
{
	if (!t) { a = b = NULL; return; }
	push(t);
	if (t -> val <= v)
	{
		a = t;
		split(t -> rc, v, a -> rc, b);
	} else
	{
		b = t;
		split(t -> lc, v, a, b -> lc);
	}
	pull(a); pull(b);
	if (a)
		if (b)
			assert(a -> val + a -> tag < b -> val + b -> tag);
}

int n;
int x[maxn], y[maxn];

void dfs(treap *t)
{
	if (!t) return;
	dfs(t -> lc);
	cout << t -> val + t -> tag << '\n';
	dfs(t -> rc);
}

void solve()
{
	while (t --> 0)
	{
		int n, m; cin >> n >> m;
		F1 (i, m)
		{
			cin >> x[i] >> y[i];
		}
		treap *t = NULL;
		F1 (i, m)
		{
			treap *a, *b, *c;
			split(t, y[i] - 1, a, c);
			split(a, y[i] - 2, a, b);
			if (c) c -> tag += 1;
			t = merge(a, merge(new treap(y[i]), c));
			//dfs(t);
			//cout << "fu\n"; 
		}
		int fu = sz(t);
		cout << C(n + n - 1 - fu, n) << '\n';
	} 
}

main()
{
	fac_init();
	input();
	solve();
}