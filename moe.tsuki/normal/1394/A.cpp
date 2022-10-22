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
int n, d, m;
int a[maxn], pre1[maxn], pre2[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> d >> m;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	vi b, s;
	F1 (i, n)
	{
		if (a[i] > m) b.pb(a[i]);
		else s.pb(a[i]);
	}
	sort(all(b));
	sort(all(s));
	reverse(all(b));
	reverse(all(s));
	F1 (i, b.size()) pre1[i] = pre1[i - 1] + b[i - 1];
	F1 (i, s.size()) pre2[i] = pre2[i - 1] + s[i - 1];
	//dbg(b); dbg(s);
	int ans = 0;
	for (int i = 0; i <= b.size() && (i - 1) * (d + 1) + 1 <= n; ++i)
	{
		// max i in b
		// max n - (i - 1) * (d + 1) - 1 in s
		int cur = 0;
		cur += pre1[i];
		
		// n - (i - 1) * (d + 1) - 1 to n - i * (d + 1)
		if (s.size() + i * (d + 1) < n) continue;
		//dbg(i); dbg(cur);
		cur += pre2[min((int) s.size(), n - (i - 1) * (d + 1) - 1)];
		ans = max(ans, cur);
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}