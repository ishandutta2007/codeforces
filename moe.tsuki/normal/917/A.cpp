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

const int maxn = 5678;
string a;
bool f[maxn][maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a;
}

#define left(x) (x == '(' || x == '?')
#define right(x) (x == ')' || x == '?')

void solve()
{
	int n = a.length(), ans = 0, cnt;
	for (int i = 0; i < n; ++i)
	{
		cnt = 0;
		for (int j = i; j < n; ++j)
		{
			if (cnt < 0) break;
			if (j != i && (j % 2 != i % 2)) { f[i][j] = true; }
			if (a[j] == ')') --cnt; else ++cnt;
		}
	}
	for (int i = n - 1; i >= 0; --i)
	{
		cnt = 0;
		for (int j = i; j >= 0; --j)
		{
			if (cnt < 0) break;
			if (j != i && (j % 2 != i % 2) && f[j][i]) ++ans;
			if (a[j] == '(') --cnt; else ++cnt;
		}
	}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}