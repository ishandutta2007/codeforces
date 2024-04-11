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
int t, n;
int a[maxn], b[maxn], c[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		cin >> n;
		F1 (i, n) cin >> a[i];
		F1 (i, n) cin >> b[i];
		F1 (i, n) cin >> c[i];
		cout << a[1] << ' ';
		int pre = a[1];
		for (int i = 2; i <= n - 1; ++i)
		{
			if (a[i] != pre)
			{
				cout << a[i] << ' ';
				pre = a[i];
			} else if (b[i] != pre)
			{
				cout << b[i] << ' ';
				pre = b[i];
			} else if (c[i] != pre)
			{
				cout << c[i] << ' ';
				pre = c[i];
			}
		}
		if (a[n] != pre && a[n] != a[1])
			{
				cout << a[n] << '\n';
			} else if (b[n] != pre && b[n] != a[1])
			{
				cout << b[n] << '\n';
			} else if (c[n] != pre && c[n] != a[1])
			{
				cout << c[n] << '\n';
			} 
	}
}

main()
{
	input();
	solve();
}