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
int t;
double a[maxn], L;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		cin >> n >> L;
		F1 (i, n) cin >> a[i];
		a[n + 1] = L;
		double t = 0;
		double at = 0, bt = 0;
		double ax = 0, bx = L;
		int l = 1, r = n;
		while (l <= r)
		{
			if ((a[l] - ax) / l + at < (bx - a[r]) / (n + 1 - r) + bt)
			{
				at += (a[l] - ax) / l;
				ax = a[l];
				++l;
			} else
			{
				bt += (bx - a[r]) / (n + 1 - r);
				bx = a[r];
				--r;
			}
		}
		// (x - at) * l + (x - bt) * (n - r + 1) = a[l] - a[r];
		cout << setprecision(20) << (a[l] - a[r] + at * l + bt * (n - r + 1)) / (n - r + l + 1) << '\n';
	}
}

main()
{
	input();
	solve();
}