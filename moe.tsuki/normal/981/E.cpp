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

const int maxn = 12345, maxl = 20;
int n, q;
bitset<maxn> lay[maxl], ans;
int l[maxn], r[maxn], x[maxn];
const int node = 345678;
int lc[node], rc[node];
vi in[node];
int cnt;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	F1 (i, q) cin >> l[i] >> r[i] >> x[i];
}

int build(int l, int r)
{
	int cur = ++cnt;
	if (l == r) return cur;
	int m = (l + r) >> 1;
	lc[cur] = build(l, m);
	rc[cur] = build(m + 1, r);
	return cur;
}

void modify(int cur, int q, int p, int l, int r, int x)
{
	//dbgg(cur); dbg(q); dbg(p);
	if (p < l || r < q) return;
	if (l <= q && p <= r) {/* MEOW; */in[cur].pb(x); return; }
	int m = (q + p) >> 1;
	modify(lc[cur], q, m, l, r, x);
	modify(rc[cur], m + 1, p, l, r, x);
}

void dfs(int cur, int hei)
{
	//dbg(cur); dbg(in[cur]);
	lay[hei] = lay[hei - 1];
	for (int x : in[cur])
	{
		lay[hei] |= lay[hei] << x;
	}
	if (!lc[cur]) 
	{ 
		ans |= lay[hei]; 
		//dbg(lay[hei].to_string());
		return; 
	}
	dfs(lc[cur], hei + 1);
	dfs(rc[cur], hei + 1);
}

void solve()
{
	build(1, n);
	F1 (i, q) modify(1, 1, n, l[i], r[i], x[i]);
	lay[0].set(0);
	dfs(1, 1);
	//cout << ans.to_string();
	int bel = 0;
	F1 (i, n) if (ans.test(i)) ++bel;
	cout << bel << '\n';
	F1 (i, n) if (ans.test(i)) cout << i << ' ';
}

main()
{
	input();
	solve();
}