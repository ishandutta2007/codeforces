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
string a, b;
int c[2][2];
int fu[114514];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cin >> a >> b;
}

void solve()
{
	F (i, n) ++c[a[i] - '0'][b[i] - '0'];
	int ans = 0;
	fu[0] = fu[1] = fu[5] = fu[7] = fu[10] = fu[11] = fu[15] = 1;
	for (int w = 0; w < 2; ++w)
	for (int x = 0; x < 2; ++x)
	for (int y = 0; y < 2; ++y)
	for (int z = 0; z < 2; ++z)
	{
		if (!fu[w * 8 + y * 4 + x * 2 + z]) continue;
		if (((w | y) == (x | y)) && ((x | z) == (w | z)))
		{
			if (w == x && y == z) ans += c[w][y] * (c[w][y] - 1) / 2;
			else ans += c[w][y] * c[x][z];
			//dbg(mp(w, y)); dbg(mp(x, z)); dbg(ans);
		}
	}
	cout << n * (n - 1) / 2 - ans << '\n';
}

main()
{
	input();
	solve();
}