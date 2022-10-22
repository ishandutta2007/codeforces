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

string a;
int n, f, u;
int ans;
int suf[123456];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a;
	n = a.length();
	cin >> f >> u;
}

void solve()
{
	if (u < f)
	{
		swap(u, f);
		F (i, n) if (a[i] != '?') a[i] = '0' + '1' - a[i];
	}
	//dbg(a);
	vi v;
	F (i, n) if (a[i] == '?') v.pb(i);
	//dbg(v);
	for (auto x : v) a[x] = '0';
	//dbg(a);
	int p = 0, q = 0, cur = 0;
	for (auto x : a)
	{
		if (x == '0') cur += q * u;
		else cur += p * f;
		if (x == '0') ++p;
		else ++q;
	}
	for (int i = n - 1; i >= 0; --i)
	{
		suf[i] = suf[i + 1];
		if (a[i] == '1') ++suf[i];
	}
	//dbg(cur);
	int cnt = 0, ans = cur;
	if (v.size())
	for (int i = v.size() - 1; i >= 0; --i)
	{
		// 0 -> 1
		cur -= (suf[v[i] + 1] + cnt) * f;
		cur += (n - v[i] - 1 - (suf[v[i] + 1] + cnt)) * u;
		cur -= (suf[0] - suf[v[i]]) * u;
		cur += (v[i] - (suf[0] - suf[v[i]])) * f;
		++cnt;
		ans = min(ans, cur);
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}