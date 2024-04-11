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
int n, m, p;
int x[maxn], cx[maxn];
int y[maxn], cy[maxn];
int px[maxn], py[maxn], c[maxn];
int lc[567890], rc[567890], mn[567890], tag[567890];
int a[maxn];
int suf[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> p;
	F1 (i, n) cin >> x[i] >> cx[i];
	F1 (i, m) cin >> y[i] >> cy[i];
	F1 (i, n) --x[i]; F1 (i, m) --y[i];
	F1 (i, p) cin >> px[i] >> py[i] >> c[i];
}

int id;

void pull(int cur)
{
	if (!lc[cur]) return;
	mn[cur] = max(mn[lc[cur]] + tag[lc[cur]], mn[rc[cur]] + tag[rc[cur]]);
}

int build(int l, int r)
{
	int cur = ++id;
	tag[cur] = 0;
	int mid = (l + r) >> 1;
	if (l == r) 
	{
		mn[cur] = a[mid];
		return cur;
	}
	lc[cur] = build(l, mid);
	rc[cur] = build(mid + 1, r);
	pull(cur);
	return cur;
}

void add(int cur, int q, int p, int l, int r, int val)
{
	/*if (cur == 1)
	{
		dbgg(l); dbgg(r);
		dbg(val);
	}*/
	if (p < l || r < q) return;
	if (l <= q && p <= r)
	{
		tag[cur] += val;
		return;
	}
	int mid = (q + p) >> 1;
	tag[lc[cur]] += tag[cur];
	tag[rc[cur]] += tag[cur];
	add(lc[cur], q, mid, l, r, val);
	add(rc[cur], mid + 1, p, l, r, val);
	tag[cur] = 0;
	pull(cur);
}

void solve()
{
	vector<pii> mm;
	F1 (i, m) mm.pb(mp(y[i], i));
	F1 (i, p) mm.pb(mp(py[i], -i));
	sort(all(mm));
	int cnt = 0;
	for (auto x : mm)
	{
		if (x.se < 0) suf[-x.se] = cnt + 1; 
		else ++cnt;
	}
	cnt = 0;
	for (auto x : mm)
	{
		if (x.se > 0)
		{
			++cnt;
			a[cnt] = -cy[x.se];
		}
	}
	//F1 (i, cnt) dbg(a[i]);
	//dbg(mm);
	//F1 (i, p) dbg(suf[i]);
	vector<pii> v;
	F1 (i, n) v.pb(mp(x[i], i));
	F1 (i, p) v.pb(mp(px[i], -i));
	sort(all(v));
	//dbg(v);
	assert(cnt == m);
	build(1, cnt);
	int ans = -2345678901ll;
	for (auto x : v)
	{
		if (x.se < 0)
			add(1, 1, cnt, suf[-x.se], cnt, c[-x.se]);
		else 
		{
			//dbg(mn[1]);
			//dbg(cx[x.se]);
			//dbg(tag[1]);
			ans = max(ans, mn[1] - cx[x.se] + tag[1]);
		}
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}