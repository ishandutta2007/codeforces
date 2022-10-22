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
const int maxn = 234567, mod = 998244353;
int a[maxn], l[maxn], r[maxn];
int app[maxn];
int b[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

#define ok(x) ((x >= 1) && (x <= n))

void solve()
{
	while (t --> 0)
	{
		int n, k; cin >> n >> k;
		F1 (i, n)
			cin >> a[i];
		F1 (i, n) app[i] = 0;
		F1 (i, k)
			cin >> b[i];
		F1 (i, k) app[b[i]] = i; 
		F1 (i, n) 
		{
			r[a[i]] = a[i + 1];
			if (i == n) r[a[i]] = 0;
		}
		F1 (i, n) 
		{
			l[a[i]] = a[i - 1];
			if (i == 1) l[a[i]] = 0;
		}
		int ans = 1;
		//F1 (i, n) dbg(app[i]);
		F1 (i, k)
		{
			int cnt = 0;
			if (ok(l[b[i]]))
			{
				if (app[l[b[i]]] < i)
					++cnt;
			}
			if (ok(r[b[i]]))
			{
				if (app[r[b[i]]] < i)
					++cnt;
			}
			ans = ans * cnt % mod;
			if (cnt == 0) break;
			//dbg(b[i]);
			//dbg(l[b[i]]);
			//dbg(r[b[i]]);
			//dbg(cnt);
			if (ok(l[b[i]]))
			{
				if (app[l[b[i]]] < i)
				{
					cnt = 0;
					r[l[l[b[i]]]] = b[i];
					l[b[i]] = l[l[b[i]]];
				}
			} 
			if (cnt)
			{
				if (app[r[b[i]]] < i)
				{
					l[r[r[b[i]]]] = b[i];
					r[b[i]] = r[r[b[i]]];
				}
			}
		}
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}