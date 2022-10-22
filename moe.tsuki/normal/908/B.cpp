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

const int maxn = 56;
int n, m, s[123];
string g[maxn];
string oper;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, n)
		cin >> g[i];
	cin >> oper;
}

void solve()
{
	int sx, sy, ex, ey, cx, cy, a[4], dy[4], dx[4];
	dy[0] = 0, dx[0] = 1;
	dy[1] = 1, dx[1] = 0;
	dy[2] = 0, dx[2] = -1;
	dy[3] = -1, dx[3] = 0;
	F1 (i, n)
		F (j, m) 
		{
			if (g[i][j] == 'S')
			{
				sy = i, sx = j;
			}
			if (g[i][j] == 'E')
			{
				ey = i, ex = j;
			}
		}
	int ans = 0;
	for (a[0] = 0; a[0] < 4; ++a[0])
		for (a[1] = 0; a[1] < 4; ++a[1])
			for (a[2] = 0; a[2] < 4; ++a[2])
				for (a[3] = 0; a[3] < 4; ++a[3])
				{
					if (a[0] == a[1]) continue;
					if (a[0] == a[2]) continue;
					if (a[0] == a[3]) continue;
					if (a[1] == a[2]) continue;
					if (a[1] == a[3]) continue;
					if (a[2] == a[3]) continue;
					F (i, oper.length())
						s[i] = a[oper[i] - '0'];
					cy = sy, cx = sx;
					for (int i = 0; i < oper.length(); ++i)
					{
						cy += dy[s[i]], cx += dx[s[i]];
						if (cy == ey && cx == ex) { ++ans; break; }
						else if (cy == 0 || cy > n || 
										 cx < 0 || cx >= m || 
										 g[cy][cx] == '#') break;
					}
				}
	cout << ans << '\n';
}

main()
{
	input();
	solve();
}