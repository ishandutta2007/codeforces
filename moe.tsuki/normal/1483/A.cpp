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

int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

const int maxn = 123456;
vi a[maxn];
int b[maxn];
int c[maxn];
vi d[maxn];

void solve()
{
	while (t --> 0)
	{
		int n, m; cin >> n >> m;
		F1 (i, m) a[i].clear();
		F1 (i, n) d[i].clear();
		F1 (i, n) b[i] = 0;
		F1 (i, m)
		{
			int k; cin >> k;
			F1 (j, k) 
			{
				int x;
				cin >> x;
				a[i].pb(x);
			}
			if (k == 1) ++b[a[i][0]];
		}
		bool ok = true;
		F1 (i, n) if (b[i] > (m + 1) / 2) ok = false;
		if (ok)
		{
			cout << "YES\n";
			F1 (i, m) 
			{
				c[i] = a[i][0];
				d[a[i][0]].pb(i);
			}
			F1 (i, n) b[i] = 0;
			F1 (i, m) ++b[c[i]];
			int mx = 0, xx;
			F1 (i, n) if (b[i] > mx) mx = b[i], xx = i;
			int fu = mx - (m + 1) / 2;
			for (auto x : d[xx])
			{
				if (a[x].size() > 1 && fu > 0)
				{
					c[x] = a[x][1];
					--fu;
				}
			}
			F1 (i, m) cout << c[i] << ' ';
			cout << '\n';
		} else cout << "NO\n";
	}
}

main()
{
	input();
	solve();
}