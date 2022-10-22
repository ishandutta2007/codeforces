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

const int maxn = 345678, pool = 1234567;
int n;
int p[maxn], q[maxn];
int pos[maxn];

int lc[pool], rc[pool];
int mx[pool], tag[pool];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> p[i];
	F1 (i, n) cin >> q[i];  
}

int id;

int build(int l, int r)
{
	int cur = ++id;
	mx[cur] = 0;
	tag[cur] = 0;
	int m = (l + r) / 2;
	if (l == r) return cur;
	lc[cur] = build(l, m);
	rc[cur] = build(m + 1, r); 
	return cur;
}

void pull(int cur)
{
	mx[cur] = max(mx[lc[cur]] + tag[lc[cur]], mx[rc[cur]] + tag[rc[cur]]);
}

void add(int cur, int q, int p, int l, int r, int val)
{
	if (q > r || p < l) return;
	if (l <= q && p <= r)
	{
		tag[cur] += val;
		return;
	}
	tag[lc[cur]] += tag[cur];
	tag[rc[cur]] += tag[cur];
	tag[cur] = 0;
	int m = (q + p) / 2;
	add(lc[cur], q, m, l, r, val);
	add(rc[cur], m + 1, p, l, r, val); 
	pull(cur);
}

void solve()
{
	build(1, 2 * n);
	int cur = n + 1;
	F1 (i, n) pos[p[i]] = i;
	F1 (i, n)
	{
		if (i != 1) add(1, 1, 2 * n, 1, 2 * q[i - 1], -1);
		while (mx[1] + tag[1] < 1)
		{
			cur--;
			add(1, 1, 2 * n, 1, 2 * pos[cur] - 1, 1);
		}
		cout << cur << ' ';
	}
}

main()
{
	input();
	solve();
}