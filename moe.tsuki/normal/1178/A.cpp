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

const int maxn = 123;
int n;
int a[maxn];
vi ans;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	int sum = 0;
	F1 (i, n) sum += a[i];
	int sum1 = a[1];
	ans.pb(1);
	for (int i = 2; i <= n; ++i) if (a[i] + a[i] <= a[1])
	{
		sum1 += a[i];
		ans.pb(i);
	}
	if (sum1 + sum1 > sum)
	{
		cout << ans.size() << '\n';
		for (auto x : ans) cout << x << ' ';
	} else cout << "0\n";
}

main()
{
	input();
	solve();
}