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
int nxt[maxn], vis[maxn], fu[maxn];;
int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n, m; cin >> n >> m;
		int ans = 0;
		F1 (i, n) nxt[i] = vis[i] = fu[i] = 0; 
		F1 (i, m) 
		{
			int x, y;
			cin >> x >> y;
			if (x != y)
			{
				nxt[x] = y;
				++ans;
			}
		}
		vi v;
		F1 (i, n) if (!vis[i] && nxt[i])
		{
			vis[i] = 1;
			fu[i] = 1;
			v.pb(i);
			int cur = i;
			while (nxt[cur])
			{
				cur = nxt[cur];
				if (vis[cur]) 
				{
					if (fu[cur])
						++ans;
					break;
				}
				else 
				{
					vis[cur] = fu[cur] = 1;
					v.pb(cur);
				}
			}
			for (auto x : v) fu[x] = 0;
			v.clear();
		}
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}