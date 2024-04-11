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
int n;
int a[maxn];
vector<pii> out;
vi E[maxn];
int ans[maxn];
int cur;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

void dfs(int x)
{
	//dbg(x);
	for (auto y : E[x])
	{
		if (a[y] == 2)
		{
			ans[y] = ans[x];
			dfs(y);
		}
		if (a[y] == 3)
		{
			ans[y] = ans[x] - 1;
			cur = min(ans[y], cur);
			out.pb(mp(ans[y], x));
			dfs(y);
		}
	}
}

void solve()
{
	stack<int> stk;
	int last = 0;
	cur = n + 1;
	bool ok = true;
	bool zero = true;
	for (int i = n; i >= 1; --i)
	{
		if (a[i] == 1)
		{
			stk.push(i);
		}
		if (a[i] == 2)
		{
			if (stk.empty())
			{
				ok = false;
				break;
			}
			last = i;
			E[stk.top()].pb(i);
			stk.pop();
		}
		if (a[i] == 3)
		{
			if (!last)
			{
				if (stk.empty())
				{
					ok = false;
					break;
				}
				last = stk.top();
				stk.pop();
			}
			E[last].pb(i);
			last = i;
		}
	}
	if (ok)
	{
		for (int i = n; i >= 1; --i)
			if ((!ans[i]) && a[i] != 0) 
			{
				ans[i] = --cur; dfs(i);
			}
		F1 (i, n)
		{
			if (ans[i])
				out.pb(mp(ans[i], i));
		}
		cout << out.size() << '\n';
		for (auto x : out)
			cout << x.fi << ' ' << x.se << '\n';
		//F1 (i, n) dbg(ans[i]);
	} else
	{
		cout << -1 << '\n';
	}
}

main()
{
	input();
	solve();
}