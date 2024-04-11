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

const int maxn = 234567;
int a[maxn];
int app[maxn];
int c[maxn];

vector<int> v[maxn];

void solve()
{
	while (t --> 0)
	{
		int n, l, r; cin >> n >> l >> r;
		F1 (i, n) cin >> a[i];
		if (l > r)
		{
			swap(l, r);
			reverse(a + 1, a + n + 1);
		}
		/*F1 (i, n) c[a[i]] = 0;
		F1 (i, n) app[a[i]] = 0;
		F1 (i, l) app[a[i]] = 1;
		F1 (i, l) ++c[a[i]];
		F1 (i, r) --c[a[i + l]];*/
		F1 (i, n) v[i].clear();
		F1 (i, n) v[a[i]].pb(i);
		int p = 0, q = 0, t = 0;
		F1 (i, n)
		{
			int cur = 0;
			for (auto x : v[i])
				if (x <= l) ++cur;
				else --cur;
			if (cur > 0) p += cur;
			else q += (-cur) / 2, t += (-cur) % 2;
			//dbg(t);
		}
		
		//dbgg(p);dbgg(q);dbg(t);
		int ans = (r - l) / 2;
		if (q > ans)
		{
			q -= ans;
		} else
		{
			p += ans - q;
			t = max(0ll, t - (ans - q)), q = 0;
		}
		cout << max(p, q * 2 + t) + ans << '\n';
		//cout << p + t + max(r - l, q) << '\n'; 
	}
}

main()
{
	input();
	solve();
}