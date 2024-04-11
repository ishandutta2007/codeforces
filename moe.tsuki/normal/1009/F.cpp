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

const int maxn = 1234567;
int n;
vi E[maxn];
int sz[maxn];
int hei[maxn];
int son[maxn];
pii fre[maxn + maxn];
int now;
pii glo;
int sft;
int tim;
pii ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n - 1)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
}

void dfs(int cur, int h)
{
	sz[cur] = 1;
	hei[cur] = h;
	int mx = 0;
	for (int x : E[cur])
	{
		if (!hei[x])
		{
			dfs(x, h + 1);
			sz[cur] += sz[x];
			if (sz[x] > mx) mx = sz[x], son[cur] = x;
		}
	}
}

void dfs_cnt(int cur)
{
	for (int x : E[cur])
	{
		if (hei[x] > hei[cur])
		{
			dfs_cnt(x);
		}
	}
	if (fre[hei[cur] - hei[now] - sft + maxn].se != tim)
		fre[hei[cur] - hei[now] - sft + maxn].fi = 0,
		fre[hei[cur] - hei[now] - sft + maxn].se = tim;
	++fre[hei[cur] - hei[now] - sft + maxn].fi;
	if (fre[hei[cur] - hei[now] - sft + maxn].fi > glo.fi)
		glo = mp(fre[hei[cur] - hei[now] - sft + maxn].fi, hei[cur] - hei[now]);
	if (fre[hei[cur] - hei[now] - sft + maxn].fi == glo.fi && hei[cur] - hei[now] <= glo.se)
		glo = mp(fre[hei[cur] - hei[now] - sft + maxn].fi, hei[cur] - hei[now]);
}

void dfs_ans(int cur, int keep)
{
	//dbg(cur);
	//MEOW
	for (int x : E[cur])
	{
		if (hei[x] > hei[cur] && x != son[cur])
		{
			dfs_ans(x, 0);
		}
	}
	if (E[cur].size() >= 2 || cur == 1)
		dfs_ans(son[cur], 1);
	else
	{
		ans[cur] = mp(1, 0);
		if (fre[-sft + maxn].se != tim)
			fre[-sft + maxn].fi = 0,
			fre[-sft + maxn].se = tim;
		++fre[-sft + maxn].fi;
		if (!keep) ++tim;
		return;
	}
	++sft;
	if (fre[-sft + maxn].se != tim)
		fre[-sft + maxn].fi = 0,
		fre[-sft + maxn].se = tim;
	++fre[-sft + maxn].fi;
	now = cur;
	glo = mp(ans[son[cur]].fi, ans[son[cur]].se + 1);
	for (int x : E[cur])
	{
		if (hei[x] > hei[cur] && x != son[cur])
			dfs_cnt(x);
	}	
	ans[cur] = glo;
	assert(fre[-sft + maxn].fi == 1);
	if (ans[cur].fi == 1) ans[cur].se = 0;
	if (!keep) ++tim;
}

void solve()
{
	dfs(1, 1);
	dfs_ans(1, 0);
	F1 (i, n) cout << ans[i].se << '\n';
}

main()
{
	input();
	solve();
}