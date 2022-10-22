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

const int maxn = 567890;
int n, m, k;
int bit[maxn];
int a[maxn], b[maxn], c[maxn];
vi E[maxn];
int cnt[maxn];

#define lowbit(x) (x & (-x))

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	F1 (i, k) cin >> c[i];
	F1 (i, m)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

void dfs(int beg, int dis[])
{
	dis[beg] = 0;
	queue<pii> q;
	q.push(mp(beg, 0));
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (auto x : E[cur.fi])
			if (!dis[x] && x != beg)
			{
				dis[x] = cur.se + 1;
				q.push(mp(x, dis[x]));
			}
	}
}

void add(int pos, int val)
{
	pos += 234567;
	while (pos < maxn)
	{
		bit[pos] += val;
		pos += lowbit(pos);
	}
}

int ask(int pos)
{
	pos += 234567;
	int ret = 0;
	while (pos)
	{
		ret += bit[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

bool ok(int cur)
{
//	dbg(cur);
	--cur;
	vector<pair<pii, int> > qry;
	F1 (i, k)
	{
		if (a[c[i]] + b[c[i]] >= cur)
			cnt[i] = -1;
		else cnt[i] = 0;
		qry.pb(mp(mp(a[c[i]] - cur, b[c[i]] - cur), i));
		qry.pb(mp(mp(-b[c[i]], -a[c[i]]), 0));
	}
	sort(all(qry));
	for (auto x : qry)
	{
		if (x.se == 0)
			add(x.fi.se, 1);
		else
			cnt[x.se] += ask(x.fi.se);
	}
	for (auto x : qry)
	{
		if (x.se == 0)
			add(x.fi.se, -1);
	}
	F1 (i, k) if (cnt[i] >= 1) return true;
	return false;
}

void solve()
{
	dfs(1, a);
	dfs(n, b);
	//F1 (i, n) dbg(a[i]);
	//F1 (i, n) dbg(b[i]);
	int cur = 0;
	int d = 1;
	while (d <= n) d <<= 1;
	while (d >>= 1)
		if (cur + d <= n && ok(cur + d)) cur += d;
	cout << min(cur, a[n]) << '\n';
}

main()
{
	input();
	solve();
}