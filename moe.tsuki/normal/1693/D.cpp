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

int n;
int a[maxn], bl[maxn], sl[maxn], br[maxn], sr[maxn], rb[maxn], rss[maxn];
int val[8901234], ls[8901234], rs[8901234];
int inv[maxn];
int roots[maxn], rootb[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

int id;

void pull(int t)
{
	val[t] = min(val[ls[t]], val[rs[t]]);
}

int build(int l, int r)
{
	int cur = ++id;
	if (l == r)
	{
		val[cur] = n + 1;
		return cur;
	}
	int m = (l + r) / 2;
	ls[cur] = build(l, m);
	rs[cur] = build(m + 1, r);
	pull(cur);
	return cur;
}

int modify(int t, int q, int p, int x, int v)
{
	int cur = ++id;
	ls[cur] = ls[t], rs[cur] = rs[t];
	if (q == p)
	{
		val[cur] = v;
		return cur;
	}
	int m = (q + p) / 2;
	if (x <= m)
	{
		ls[cur] = modify(ls[cur], q, m, x, v);
	} else
	{
		rs[cur] = modify(rs[cur], m + 1, p, x, v);
	}
	pull(cur);
	return cur;
}

int query(int cur, int q, int p, int l, int r)
{
	if (q > r || p < l) return maxn;
	int m = (q + p) / 2;
	if (l <= q && p <= r) return val[cur];
	return min(query(ls[cur], q, m, l, r), query(rs[cur], m + 1, p, l, r));
}

void solve()
{
	//build(1, n);
	int r = 1;
	long long ans = 0;
	stack<int> s;
	F1 (i, n)
	{
		while (!s.empty())
		{
			if (a[s.top()] > a[i])
			{
				bl[i] = s.top();
				break;
			}
			else s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) s.pop();
	F1 (i, n)
	{
		while (!s.empty())
		{
			if (a[s.top()] < a[i])
			{
				sl[i] = s.top();
				break;
			}
			else s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) s.pop();
	F1 (i, n) br[i] = n + 1;
	for (int i = n; i >= 1; --i)
	{
		while (!s.empty())
		{
			if (a[s.top()] > a[i])
			{
				br[i] = s.top();
				break;
			}
			else s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) s.pop();
	F1 (i, n) sr[i] = n + 1;
	for (int i = n; i >= 1; --i)
	{
		while (!s.empty())
		{
			if (a[s.top()] < a[i])
			{
				sr[i] = s.top();
				break;
			}
			else s.pop();
		}
		s.push(i);
	}
	F1 (i, n)
		rss[a[i]] = sr[i];
	F1 (i, n)
		rb[a[i]] = br[i];
	F1 (i, n) inv[a[i]] = i;
	//F1 (i, n) dbg(mp(sl[i], bl[i]));
	roots[0] = build(1, n);
	F1 (i, n)
		roots[i] = modify(roots[i - 1], 1, n, inv[i], rss[i]);
	rootb[n + 1] = build(1, n);
	for (int i = n; i >= 1; --i)
		rootb[i] = modify(rootb[i + 1], 1, n, inv[i], rb[i]);
	for (int l = 1; l <= n; ++l)
	{
		r = max(l, r);
		while (r < n)
		{
			int cur = r + 1;
			//dbg(mp(l, cur));
			if (bl[cur] >= l + 1)
			{
				//dbg(mp(query(roots[a[cur] - 1], 1, n, l, bl[cur] - 1), bl[cur]));
				if (query(roots[a[cur] - 1], 1, n, l, bl[cur] - 1) <= bl[cur])
					break;
			}
			if (sl[cur] >= l + 1)
			{
				//dbg(mp(query(rootb[a[cur] + 1], 1, n, l, sl[cur] - 1), sl[cur]));
				if (query(rootb[a[cur] + 1], 1, n, l, sl[cur] - 1) <= sl[cur])
					break;
			}
			++r;
		}
		ans += r - l + 1;
	}
	cout << ans << '\n';
}

main()
{
	fac_init();
	input();
	solve();
}