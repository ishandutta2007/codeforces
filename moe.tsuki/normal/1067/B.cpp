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

const int maxn = 123456;
int n, k;
vi E[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	F1 (i, n - 1)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y); E[y].pb(x);
	}
}

vi v;
int used[maxn];

int dfs_mid(int x, int y, int par, int len)
{
	v.pb(x);
	if (y == x) 
	{
		int ret = len & 1 ? v[(len + 1) / 2 - 1] : 0;
		auto t = v.end(); --t;
		v.erase(t);
		return ret;
	}
	int ret = 0;
	for (auto cur : E[x]) if (cur != par)
	{
		
		if (used[cur]) continue;
		ret = max(ret, dfs_mid(cur, y, x, len + 1));
	}
	auto t = v.end(); --t;
	v.erase(t);
	return ret;
}

pii dfsf(int cur, int par)
{
	pii ret = mp(cur, 0); 
	for (auto m : E[cur])
	{
		if (m != par) 
		{
			if (used[m]) continue;
			auto now = dfsf(m, cur);
			if (now.se + 1 > ret.se) { ret.fi = now.fi; ret.se = now.se + 1; }
		}
	}
	return ret;
}



int decom(int cur, int k)
{
	if (k == 0)
	{
		int ok = true;
		for (auto m : E[cur]) if (!used[m]) ok = false;
		if (ok) return 1;
		else return 0;
	}
	int x = dfsf(cur, 0).fi;
	//dbg(x); 
	int y = dfsf(x, 0).fi;
	//dbg(y);
	int z = dfs_mid(x, y, 0, 1);
	//dbg(z);
	if (!z) return false;
	used[z] = true;
	int ans = 0; bool ok = true;
	for (auto m : E[z]) 
	{
		if (!used[m]) 
		{
			int t = decom(m, k - 1);
			if (t) ++ans;
			else ok = false;
		}
	}
	if (ans >= 3 && ok) return 1;
	return 0;
}

void solve()
{
	if (decom(1, k)) cout << "Yes\n";
	else cout << "No\n";
}

main()
{
	input();
	solve();
}