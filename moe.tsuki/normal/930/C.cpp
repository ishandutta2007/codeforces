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

const int maxn = 1234567;
int n, m, a[maxn], bit[maxn], l[maxn], r[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, n)
	{
		int l, r; cin >> l >> r;
		--a[r + 1]; ++a[l];
	}
}

#define lowbit(x) ((x) & -(x))

int query(int pos)
{
	int res = 0;
	while (pos)
	{
		res = max(res, bit[pos]);
		pos -= lowbit(pos);
	}
	return res;
}

void add(int pos, int val)
{
	if (pos == 0) return;
	while (pos < maxn)
	{
		bit[pos] = max(bit[pos], val);
		pos += lowbit(pos);
	}
}

void solve()
{
	F1 (i, m) a[i] += a[i - 1];
	F1 (i, m) ++a[i];
	//F1 (i, m) dbgg(a[i]);
	
	for (int i = 1; i <= m; ++i)
	{
		l[i] = query(a[i]);
		add(a[i], l[i] + 1);
	}
	
	//F1 (i, m) dbg(l[i]);
	
	F (i, maxn) bit[i] = 0;
	for (int i = m; i >= 1; --i)
	{
		r[i] = query(a[i]);
		add(a[i], r[i] + 1);
	}
	
	//F1 (i, m) dbg(r[i]);
	
	int ans = 0;
	F1 (i, m) ans = max(ans, l[i] + r[i]);
	cout << ans + 1 << '\n';
}

main()
{
	input();
	solve();
}