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

const int maxn = 1234;
int n;
map<int, int> c;
vi e[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F (i, n - 1) 
	{
		int x; cin >> x; ++c[x];
		e[x].pb(i + 2);
	}
}

void solve()
{
	int flag = 1;
	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0;
		if (!c[i]) continue;
		for (int j : e[i]) if (c[j] == 0) ++cnt;
		if (cnt < 3) flag = 0;
	}
	if (flag) cout << "Yes\n";
	else cout << "No\n";
}

main()
{
	input();
	solve();
}