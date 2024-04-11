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

const int maxn = 345678, maxt = 1234567, oo = 123456789;
int n, q;
int a[maxn];
vector<pii> Q[maxn];
int cnt;
int v[maxt];
pii mn[maxt];
int lc[maxt];
int rc[maxt];
int tag[maxt];
int bit[maxn];
int ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	F1 (i, n) cin >> a[i];
	F1 (i, q)
	{
		int x, y; cin >> x >> y;
		Q[x].pb(mp(i, y));
	}
}

void pull(int cur)
{
	mn[cur] = min(mn[lc[cur]], mn[rc[cur]]);
	mn[cur].fi += tag[cur];
}

int build(int l, int r)
{
	int cur = ++cnt;
	if (l == r) 
	{
		int val = l - a[l];
		if (val < 0) val = oo;
		v[cur] = val;
		mn[cur] = mp(val, l);
		return cur;
	}
	int m = (l + r) / 2;
	lc[cur] = build(l, m);
	rc[cur] = build(m + 1, r);
	pull(cur);
	return cur;
}

void modify(int cur, int l, int r, int pos)
{
	if (l == r) 
	{
		v[cur] = oo;
		mn[cur].fi = oo;
		return;
	}
	int m = (l + r) / 2;
	if (m >= pos)
		modify(lc[cur], l, m, pos);
	else
		modify(rc[cur], m + 1, r, pos);
	pull(cur);
}

void add(int cur, int l, int r, int pos)
{
	int m = (l + r) / 2;
	if (l > n || r < pos)
		return;
	if (pos <= l)
	{
		--tag[cur];
		--mn[cur].fi;
		return;
	}
	add(lc[cur], l, m, pos);
	add(rc[cur], m + 1, r, pos);
	pull(cur);
}

pii query(int cur, int l, int r, int pos)
{
	int m = (l + r) / 2;
	if (l > n || r < pos)
		return mp(oo, oo);
	if (pos <= l)
		return mn[cur];
	tag[lc[cur]] += tag[cur];
	tag[rc[cur]] += tag[cur];
	mn[lc[cur]].fi += tag[cur];
	mn[rc[cur]].fi += tag[cur];
	tag[cur] = 0;
	auto x = query(lc[cur], l, m, pos);
	auto y = query(rc[cur], m + 1, r, pos);
	pull(cur);
	return min(x, y);
}

#define lowbit(x) (x & (-x))

void mod(int pos)
{
	//cout << "Added\n";
	//dbg(pos);
	while (pos < maxn)
	{
		++bit[pos];
		pos += lowbit(pos);
	}
}

int sum(int pos)
{
	int res = 0;
	while (pos)
	{
		res += bit[pos];
		pos -= lowbit(pos);
	}
	return res;
}

void solve()
{
	build(1, n);
	queue<int> que;
	for (int i = n; i >= 1; --i)
	{
		//cout << "Now at\n";
		//dbg(i);
		if (a[i] == i)
		{
			mod(i);
			que.push(i);
			modify(1, 1, n, i);
		}
		while (true)
		{
			while (!que.empty())
			{
				int cur = que.front();
				que.pop();
				//dbg(cur);
				if (cur == n) continue;
				add(1, 1, n, cur + 1);
				auto x = query(1, 1, n, cur + 1);
				//dbg(x);
				if (x.fi <= 0)
				{
					mod(x.se);
					modify(1, 1, n, x.se);
					que.push(x.se);
				}
			}
			auto x = query(1, 1, n, i);
			if (x.fi <= 0)
			{
				//dbg(x);
				mod(x.se);
				modify(1, 1, n, x.se);
				que.push(x.se);
			} else break;
		}
		for (auto x : Q[i - 1])
		{
			ans[x.fi] = sum(n - x.se);
			//dbg(sum(n - x.se));
		}
	}
	F1 (i, q) cout << ans[i] << '\n';
}

main()
{
	input();
	solve();
}