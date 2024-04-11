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

const int maxn = 567;
int n;
int p[maxn];
int ans[maxn][maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	F1 (i, n) cin >> p[i];
}

void solve()
{
	F1 (i, n)
	{
		int x = i, y = i;
		int j = p[i];
		while (j --> 0)
		{
			//dbg(mp(x, y));
			ans[x][y] = p[i];
			if (y >= 2 && ans[x][y - 1] == 0) --y;
			else ++x;
		}
	}
	F1 (i, n)
	{
		F1 (j, i)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}

main()
{
	input();
	solve();
}