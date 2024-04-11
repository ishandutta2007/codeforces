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

const int maxn = 1234;
int n;
vi E[maxn];
int vis[maxn];

void input()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n - 1)
	{
		int x, y; cin >> x >> y;
		E[x].pb(y); E[y].pb(x);	
	}
}

int ans;
int gett;

void ask(int x, int y)
{
	cout << "? " << x << ' ' << y << '\n';
	fflush(stdout);
	cin >> gett;
}

void gao(int cur)
{
	vis[cur] = 1;
	vi sub;
	for (auto x : E[cur]) 
		if (vis[x] != -1) 
			sub.pb(x);
	F (i, sub.size() / 2)
	{
		ask(sub[i + i], sub[i + i + 1]);
		if (gett != cur) 
		{
			if (vis[gett] == 1) 
			{
				ans = gett;
				return;
			}
			vis[cur] = -1;
			gao(gett);
			return;
		}
	}
	if (sub.size() & 1)
	{
		if (vis[sub[sub.size() - 1]] == 1)
		{
			ask(cur, sub[sub.size() - 1]);
			ans = gett;
			return;
		}
		else gao(sub[sub.size() - 1]);
	}
	else ans = cur;
}

void solve()
{
	gao(1);
	cout << "! " << ans << '\n';
}

main()
{
	input();
	solve();
}