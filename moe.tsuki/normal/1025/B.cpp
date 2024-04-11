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
int sie[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
}

void solve()
{
	int x, y; cin >> x >> y;
	set<int> a[2];
	
	vi p;
	bool X = false, Y = false;
	for (int i = 2; i < maxn; ++i)
	{
		if (!sie[i]) 
		{
			p.pb(i);
			if (x % i == 0)
			{
				a[0].insert(i);
			}
			while (x % i == 0) x /= i;
			if (y % i == 0)
			{
				a[0].insert(i);
			}
			while (y % i == 0) y /= i;
		}
		for (int j = i; j < maxn; j += i) sie[j] = true;
	}
	if (x != 1) a[0].insert(x);
	if (y != 1) a[0].insert(y); 
	//dbg("gwewge");
	F1 (i, n - 1)
	{
		//dbg(i);
		int cur = i & 1;
		int last = cur ^ 1;
		a[cur].clear();
		
		cin >> x >> y;
		for (int k : a[last]) 
		{
			//dbg(k);
			if (x % k == 0 || y % k == 0) a[cur].insert(k);
		}
	}
	if (a[(n - 1) & 1].size()) cout << *a[(n - 1) & 1].begin() << '\n';
	else cout << -1 << '\n';
}

main()
{
	input();
	solve();
}