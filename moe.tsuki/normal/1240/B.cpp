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

const int maxn = 345678;
int q;
int a[maxn];
int l[maxn], r[maxn];
int be[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> q;
}

void solve()
{
	while (q --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		map<int, vi> m;
		F1 (i, n) m[a[i]].pb(i);
		int ptr = 0;
		for (auto x : m)
			l[++ptr] = x.se[0], r[ptr] = x.se[x.se.size() - 1];
		be[1] = 1;
		for (int i = 2; i <= ptr; ++i)
		{
			if (r[i - 1] < l[i]) be[i] = be[i - 1];
			else be[i] = i;
		}
		int ans = maxn;
		//dbg(ptr);
		//F1 (i, ptr) { dbgg(l[i]); dbg(r[i]); }
		//F1 (i, ptr) dbg(be[i]);
		for (int i = ptr; i >= 1; --i)
		{
			ans = min(ans, (ptr - i) + (be[i] - 1));
		}
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}