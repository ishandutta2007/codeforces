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
string s[345];
int cnt[3][2];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		F (i, n) cin >> s[i];
		F (i, 2)
			F (j, 3)
				cnt[j][i] = 0;
		F (i, n) F (j, n) 
			if (s[i][j] == 'X')
				++cnt[(i + j) % 3][0];
			else if (s[i][j] == 'O')
				++cnt[(i + j) % 3][1];
		int ans = 1234567489;
		pii opt;
		F (i, 3) F (j, 3)
			if (i == j) continue;
			else 
			{
				if (ans > cnt[i][0] + cnt[j][1])
				{
					ans = cnt[i][0] + cnt[j][1];
					opt = mp(i, j);
				}
			}
		/*F (i, 3)
		{
			dbgg(cnt[i][0]);
			dbg(cnt[i][1]);
		}*/
		F (i, n) F (j, n) 
			if (s[i][j] == 'X')
			{
				if ((i + j) % 3 == opt.fi) s[i][j] = 'O';
			}
			else if (s[i][j] == 'O')
			{
				if ((i + j) % 3 == opt.se) s[i][j] = 'X';
			}
		//dbg(ans);
		F (i, n) cout << s[i] << '\n';
	}
}

main()
{
	input();
	solve();
}