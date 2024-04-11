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
int n, m, k;
int a[maxn], b[maxn];
set<int> fri[maxn];
vector<pii> eve;
int deg[maxn];
int ans[maxn];
bool kil[maxn];
map<int, bool> app;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	F1 (i, m) 
	{
		cin >> a[i] >> b[i];
		fri[a[i]].insert(b[i]);
		fri[b[i]].insert(a[i]);
		++deg[a[i]]; ++deg[b[i]];
	}
}

void rem(int a, int b)
{
	if (fri[a].lower_bound(b) == fri[a].end()) return;
	if (*fri[a].lower_bound(b) != b) return;	
	eve.pb(mp(a, b));
	fri[a].erase(b);
	fri[b].erase(a);
	--deg[a]; --deg[b];
	if (deg[a] < k && !kil[a])
	{
		kil[a] = true;
		vector<int> tmp;
		for (auto x : fri[a]) tmp.pb(x);
		for (auto x : tmp) rem(a, x);
		assert(fri[a].size() == 0);
	}
	if (deg[b] < k && !kil[b])
	{
		kil[b] = true;
		vector<int> tmp;
		for (auto x : fri[b]) tmp.pb(x);
		for (auto x : tmp) rem(b, x);
		assert(fri[b].size() == 0);
	}
}

void solve()
{
	F1 (i, n) if (deg[i] < k) 
	{
		if (!kil[i] && fri[i].size()) rem(i, *fri[i].begin());
	}
	for (int i = m; i >= 1; --i)
	{
		eve.pb(mp(0, i));
		rem(a[i], b[i]);
	}
	int sum = 0;
	reverse(all(eve));
	for (auto cur : eve)
	{
		if (cur.fi == 0) 
		{ 
			ans[cur.se] = sum; 
			continue; 
		}
		if (!app[cur.fi]) app[cur.fi] = true, ++sum;
		if (!app[cur.se]) app[cur.se] = true, ++sum;
	}
	F1 (i, m) cout << ans[i] << '\n';
}

main()
{
	input();
	solve();
}