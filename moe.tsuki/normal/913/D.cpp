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

const int maxn = 234567;
int n, d, v[maxn], s[maxn];
vi vec[maxn];

struct treap
{
	treap *lc, *rc;
	int size, val, sum, ind;
	treap (int v, int k)
	{
		lc = rc = NULL;
		size = 1;
		sum = val = v;
		ind = k;
	}
};
#define sz(x) (x ? x -> size : 0)

void pull(treap *x)
{
	
	if (!x) return;
	x -> sum = x -> val;
	if (x -> lc) x -> sum += x -> lc -> sum;
	if (x -> rc) x -> sum += x -> rc -> sum;
	x -> size = 1 + sz(x -> lc) + sz(x -> rc);
}

treap *merge(treap *a, treap *b)
{
	if (!a) return b; if (!b) return a;
	treap *ret;
	if (rand() % (sz(a) + sz(b)) < sz(a))
	{
		ret = a;
		ret -> rc = merge(a -> rc, b);
	} else
	{
		ret = b;
		ret -> lc = merge(a, b -> lc);
	}
	pull(ret); return ret;
}

void splits(treap *t, int s, treap *&a, treap *&b)
{
	if (!t) { a = b = NULL; return; }
	if (s <= sz(t -> lc))
	{
		b = t;
		splits(b -> lc, s, a, b -> lc);
	} else
	{
		a = t;
		splits(a -> rc, s - sz(t -> lc) - 1, a -> rc, b);
	}
	pull(a); pull(b);
}

void splitv(treap *t, int s, treap *&a, treap *&b)
{
	if (!t) { a = b = NULL; return; }
	if (s < t -> val)
	{
		b = t;
		splitv(b -> lc, s, a, b -> lc);
	} else
	{
		a = t;
		splitv(a -> rc, s, a -> rc, b);
	}
	pull(a); pull(b);
}

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> d;
	F1 (i, n)
	{
		cin >> v[i] >> s[i];
		vec[v[i]].pb(i);
	}
}

void dfs(treap *x)
{
	if (!x) return;
	cout << x -> ind << ' ';
	dfs(x -> lc); dfs(x -> rc);
}

void solve()
{
	int ans = 0;
	treap *t = NULL;
	for (int i = n; i >= 1; --i)
	{
		//dbg(i);
		for (int x : vec[i])
		{
			treap *p, *q;
			splitv(t, s[x], p, q);
			t = merge(merge(p, new treap(s[x], x)), q);
		}
		treap *a, *b;
		splits(t, i, a, b);
		if (a && sz(a) == i && a -> sum <= d) { ans = i; t = a; break; }
		t = merge(a, b);
	}
	
	cout << ans << '\n';
	if (ans)
	{
		cout << sz(t) << '\n';
		dfs(t);
	} else cout << "0\n";
}

main()
{
	input();
	solve();
}