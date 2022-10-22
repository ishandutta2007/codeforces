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
int a[maxn], b[maxn];
void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n; n /= 2;
	F1 (i, n) cin >> a[i];
}

pair<bool, int> gao(int last, int sec)
{
	bool ok = false;
	int ret = 100000000000000000ll;
	for (int i = 1; i * i <= sec; ++i)
	{
		if (sec % i) continue;
		int a = i, b = sec / i;
		if ((a + b) & 1) continue;
		int c = (b - a) / 2, d = (a + b) / 2;
		if (c * c > last) { ok = true; ret = min(ret, d * d); }
	}
	return mp(ok, ret);
}

void solve()
{
	int last = 0;
	F1 (i, n)
	{
		auto res = gao(last, a[i]);
		if (!res.fi) { cout << "No\n"; return; }
		b[i] = res.se - last - a[i];
		last = res.se;
	}
	cout << "Yes\n";
	F1 (i, n) { cout << b[i] << ' ' << a[i] << ' '; }
}

main()
{
	input();
	solve();
}