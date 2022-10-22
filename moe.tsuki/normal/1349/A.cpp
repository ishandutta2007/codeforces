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
 
const int maxn = 123456, maxt = 234567;
int n;
int a[maxn];
 
void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n)
		cin >> a[i];
}
 
vi p;
vi m[maxt];
 
void solve()
{
	F1 (i, n)
	{
		for (int j = 2; j <= a[i]; ++j)
		{
			int cur = 0;
			if (j * j > a[i])
			{
				m[a[i]].pb(1);
				break;
			}
			if (a[i] % j == 0)
			{
				while (a[i] % j == 0) a[i] /= j, ++cur;
				m[j].pb(cur);
			}
		}
	}
	int ans = 1;
	F (i, maxt)
	{
		int cur = 0;
		if (m[i].size() <= n - 2) cur = 0;
		else 
		{
			cur = 10000;
			for (auto t : m[i]) cur = min(cur, t); 
			if (m[i].size() == n - 1) ;
			else 
			{
				int cnt = 0;
				for (auto t : m[i]) if (t == cur) ++cnt;
				if (cnt >= 2) ;
				else
				{
					int curr = 10000;
					for (auto t : m[i]) if (t != cur) curr = min(curr, t);
					cur = curr;
				}
			}
		}
		while (cur --> 0) ans *= i;
	}
	cout << ans << '\n';
}
 
main()
{
	input();
	solve();
}