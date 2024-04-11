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
int n, m, k;

vector<pii> E[maxn];
int x[maxn];
int pa[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	F1 (i, k) cin >> x[i];
	F1 (i, m)
	{
		int x, y, w; cin >> x >> y >> w;
		E[x].pb(mp(y, w)); E[y].pb(mp(x, w));
	}
	
}

int find(int x)
{
	if (x == pa[x]) return x;
	return pa[x] = find(pa[x]);
}

bool check(int val)
{
	F1 (i, n) pa[i] = i;
	F1 (i, n)
	{
		for (auto x : E[i])
		{
			if (x.se <= val)
				pa[find(i)] = pa[find(x.fi)];
		}
	}
	int ans = true;
	int last = find(x[1]);
	F1 (i, k) if (last != find(x[i])) ans = false;
	return ans;
}

void solve()
{
	int ans = 0;
	int step = 1ll << 30;
	while (step >>= 1)
	{
		if (!check(ans + step)) ans += step;
	}
	F1 (i, k) cout << ans + 1 << ' ';
}

main()
{
	input();
	solve();
}