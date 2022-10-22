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

const int oo = 8000000000000000000ll;
int t;
int ans;
vi A, B, C;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void gao(vi a, vi b, vi c)
{
	int ret = oo;
	for (auto x : a)
	{
		int r, s;
		auto p = lower_bound(all(b), x);
		if (p == b.end() || *p > x)
		{
			if (p == b.begin()) continue;
			--p;
			r = x - *p;
		} else if (*p == x)
		{
			r = 0;
		}
		p = lower_bound(all(c), x);
		if (p == c.end()) continue;
		s = *p - x;
		ret = min(ret, (r * r + s * s + r * s) * 2);
	}
	ans = min(ans, ret);
}

void solve()
{
	while (t --> 0)
	{
		int a, b, c; cin >> a >> b >> c;
		A.clear(); B.clear(); C.clear();
		F1 (i, a)
		{
			int x; cin >> x;
			A.pb(x);
		}
		F1 (i, b)
		{
			int x; cin >> x;
			B.pb(x);
		}
		F1 (i, c)
		{
			int x; cin >> x;
			C.pb(x);
		}
		sort(all(A));
		sort(all(B));
		sort(all(C));
		ans = oo;
		gao(A, B, C);
		gao(A, C, B);
		gao(B, A, C);
		gao(B, C, A);
		gao(C, A, B);
		gao(C, B, A);
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}