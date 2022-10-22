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

const int maxn = 234567, oo = 123456789, mm = 1234567;
int n;
int a[maxn];
bool si[mm];
vi pr;
vi cand;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	
	int ans = oo;
	
	for (int i = 2; i < mm; ++i)
	{
		if (!si[i]) pr.pb(i);
		for (int j = i + i; j < mm; j += i)
			si[j] = true;
	}
	
	F1 (i, 20)
	{
		int x = rand() * rand() % n * rand() % n + 1;
		if (a[x] > 1)
		cand.pb(a[x] - 1);
		cand.pb(a[x]);
		cand.pb(a[x] + 1);
	}
	
	set<int> s;
	
	for (auto x : cand)
	{
		if (x >= 0)
		{
			for (auto y : pr)
			{
				if (y * y > x) break;
				if (x % y == 0) s.insert(y);
				while (x % y == 0) x /= y;
			}
			if (x != 1) s.insert(x);
		}
	}
	
	for (auto x : s)
	{
		int cur = 0;
		F1 (i, n)
		{
			if (a[i] < x) cur += x - a[i];
			else 
			{
				int c = a[i] % x;
				cur += min(c, x - c);
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}