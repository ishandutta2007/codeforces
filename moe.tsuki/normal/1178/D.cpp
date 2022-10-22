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

const int maxn = 2345;
int n;
int sf[maxn];
vi p;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
}

int f(int x)
{
	if (x > n) return x - n;
	return x;
}

void solve()
{
	for (int i = 2; i < maxn; ++i)
	{
		if (!sf[i])
		{
			p.pb(i);
			sf[i] = i;
		}
		for (auto x : p)
		{
			if (i * x >= maxn) break;
			sf[i * x] = x;
			if (i % x == 0) break;
		}
	}
	int e = n;
	int cur = 1;
	vector<pii> ans;
	while (sf[e] != e)
	{
		ans.pb(mp(f(cur), f(cur + 2)));
		if (cur % 4 == 1) 
			++cur;
		else cur += 3;
		++e;
	}
	cout << e << '\n';
	for (auto x : ans)
		cout << x.fi << ' ' << x.se << '\n';
	F1 (i, n - 1) cout << i << ' ' << i + 1 << '\n';
	cout << 1 << ' ' << n << '\n';
}

main()
{
	input();
	solve();
}