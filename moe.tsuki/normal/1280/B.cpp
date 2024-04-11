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

int t;
string s[67];
int r[67];
int c[67];
int ans;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void check(int p, int q, int r, int t, int v)
{
	int fu = 1;
//dbgg(p); dbgg(q); dbgg(r); dbg(t);
	for (int i = p; i <= r; ++i)
	{
		for (int j = q; j <= t; ++j)
		{
			if (s[i][j] != 'A') fu = 0;
			//cout << s[i][j];
		}
		//cout << '\n';
	}
	if (fu) ans = v;
}

void solve()
{
	while (t --> 0)
	{
		ans = 12345;
		int n, m; cin >> n >> m;
		F (i, n) cin >> s[i];
		F (i, n) F (j, m) check(i, j, i, j, 4);
		F (i, n) check(i, 0, i, 0, 3);
		F (i, n) check(i, m - 1, i, m - 1, 3);
		F (i, m) check(0, i, 0, i, 3);
		F (i, m) check(n - 1, i, n - 1, i, 3);
		/*F (i, n) r[i] = false;
		F (i, m) c[i] = false;
		F (i, n) F (j, m)
			if (s[i][j] == 'A')
				r[i] = true, c[j] = true;
		bool fu = 1;
		F (i, n) fu &= r[i];
		if (fu) ans = 2;
		fu = 1;
		F (i, m) fu &= c[i];
		if (fu) ans = 2;
		//dbg(ans);*/
		F (i, n) check(i, 0, i, m - 1, 2);
		F (i, m) check(0, i, n - 1, i, 2);
		check(0, 0, 0, 0, 2);
		check(0, m - 1, 0, m - 1, 2);
		check(n - 1, 0, n - 1, 0, 2);
		check(n - 1, m - 1, n - 1, m - 1, 2);
		check(0, 0, 0, m - 1, 1);
		check(0, 0, n - 1, 0, 1);
		check(0, m - 1, n - 1, m - 1, 1);
		check(n - 1, 0, n - 1, m - 1, 1);
		check(0, 0, n - 1, m - 1, 0);
		if (ans != 12345)
			cout << ans << '\n';
		else cout << "MORTAL\n";
	}
}

main()
{
	input();
	solve();
}