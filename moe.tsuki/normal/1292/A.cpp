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
#define mineq(x,y) { if ((x) > (y)n) (x) = (y); }
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
int n, q;
int a[2][maxn];
int x[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
}

void solve()
{
	int sum = 0;
	F1 (i, q)
	{
		int r, c; cin >> r >> c;
		--r;
		a[r][c] ^= 1;
		if (c > 1)
		{
			if ((a[0][c] || a[0][c - 1]) && (a[1][c] || a[1][c - 1]))
			{
				sum -= x[c - 1];
				x[c - 1] = 1;
				sum += x[c - 1];
			} else
			{
				sum -= x[c - 1];
				x[c - 1] = 0;
				sum += x[c - 1];
			}
		}
		if (c < n)
		{
			if ((a[0][c] || a[0][c + 1]) && (a[1][c] || a[1][c + 1]))
			{
				sum -= x[c];
				x[c] = 1;
				sum += x[c];
			} else
			{
				sum -= x[c];
				x[c] = 0;
				sum += x[c];
			}
		}
		///dbg(sum);
		if (sum == 0) cout << "Yes\n";
		else cout << "No\n";
	}
}

main()
{
	input();
	solve();
}