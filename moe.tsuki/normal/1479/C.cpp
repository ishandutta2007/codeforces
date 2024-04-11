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

int l, r;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> l >> r;
}

int zog[1234567];
int a[34][34];

void solve()
{
	cout << "YES" << '\n';
	// a[1][n] = l;
	r -= l;
	int cur = r;
	int d = 1;
	int cnt = 0;
	while (d <= cur) 
	{
		zog[d] = cnt++;
		d <<= 1;
	}
	int add = 0;
	int off = 2;
	a[1][32] = l;
	while (d >>= 1)
	{
		if (d & cur) 
		{
			a[1][20 - zog[d] + off] = l + add;
			add += d;
		}
	}
	for (int i = 0; i < 21; ++i)
	{
		a[20 - i + off][32] = 1;
		for (int j = i - 1; j >= 0; --j)
			a[20 - i + off][20 - j + off] = 1 << j;
	}
	vector<pii> ans;
	cout << 32 << ' ';
	F1 (i, 32) F1 (j, 32) if (a[i][j])
	{
		ans.pb(mp(i, j));
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x.fi << ' ' << x.se << ' ' << a[x.fi][x.se] << '\n';
}

main()
{
	input();
	solve();
}