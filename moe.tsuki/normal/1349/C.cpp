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

int n, m, t;
string s[1234];
int dx[4], dy[4];
int tim[1234][1234];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> t;
	F1 (i, n) { cin >> s[i]; s[i] = " " + s[i] + " "; }
	s[0] = s[n + 1] = "";
	F1 (i, m + 2) s[0] += " ", s[n + 1] += " ";
}

queue<pii> que;

void solve()
{
	dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
	dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
	F1 (i, n) F1 (j, m)
	{
		F (k, 4) 
		{
			if (s[i][j] == s[i + dx[k]][j + dy[k]]) 
			{
				tim[i][j] = 1;
				//dbg(k); dbg(mp(i, j)); dbg(i + dx[k], j + dy[k]);
			}
		}
		if (tim[i][j]) que.push(mp(i, j));
	}
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();
		int i = cur.fi, j = cur.se;
		F (k, 4)
			if (!tim[i + dx[k]][j + dy[k]] && s[i + dx[k]][j + dy[k]] != ' ')
			{
				tim[i + dx[k]][j + dy[k]] = tim[i][j] + 1;
				que.push(mp(i + dx[k], j + dy[k]));
			}
	}
	F1 (i, n) F1 (j, m) if (!tim[i][j]) tim[i][j] = 2000000000000000000ll;
	while (t --> 0)
	{
		int i, j, p;
		cin >> i >> j >> p;
		if (p >= tim[i][j])	
		{
			int ori = 0;
			if (s[i][j] == '1') ori = 1;
			cout << (ori ^ ((p - tim[i][j] + 1) & 1)) << '\n';
		}
		else cout << s[i][j] << '\n';
	}
}

main()
{
	input();
	solve();
}