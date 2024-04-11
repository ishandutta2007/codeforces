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

const int maxn = 12345, maxt = 1234, oo = 10000000000000000ll;
int n, m;
int d[maxn];
int a[maxn];
int g, r;
bool vis[maxn][maxt];
int ans[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, m) cin >> d[i];
	cin >> g >> r;
}

queue<pair<pii, int> > q[2];

void solve()
{
	sort(d + 1, d + m + 1);
	F1 (i, m - 1) a[i] = d[i + 1] - d[i];
	
	
	
	//F1 (i, m - 1) dbg(a[i]);
	//F1 (i, m) dbg(d[i]);
	q[0].push(mp(mp(1, 0), 0)); 
	// at, interval, min 
	int i = 0;
	while ((!q[0].empty()) || (!q[1].empty()))
	{
		while (!q[i].empty())
		{
			auto cur = q[i].front();
			q[i].pop();
			//dbg(mp(cur.se, cur.fi));
			if (!vis[cur.fi.fi][cur.fi.se])
			{
				vis[cur.fi.fi][cur.fi.se] = true;
				if (cur.fi.se == 0) ans[cur.fi.fi] = cur.se;
				if (cur.fi.fi != 1)
				{
					auto nxt = cur;
					nxt.fi.fi = cur.fi.fi - 1;
					nxt.fi.se = cur.fi.se + a[cur.fi.fi - 1];
					nxt.se = cur.se;
					if (nxt.fi.se < g)
						q[i].push(nxt);
					else if (nxt.fi.se == g)
					{
						nxt.fi.se = 0;
						++nxt.se;
						q[i ^ 1].push(nxt);
					}
				}
				if (cur.fi.fi != m)
				{
					auto nxt = cur;
					nxt.fi.fi = cur.fi.fi + 1;
					nxt.fi.se = cur.fi.se + a[cur.fi.fi];
					nxt.se = cur.se;
					
					//dbg(mp(nxt.se, nxt.fi));
					
					if (nxt.fi.se < g)
						q[i].push(nxt);
					else if (nxt.fi.se == g)
					{
						nxt.fi.se = 0;
						++nxt.se;
						q[i ^ 1].push(nxt);
					}
				}
			}
		}
		i ^= 1;
	}
	int Ans = oo; 
	F1 (i, m)
	{
		if (d[m] - d[i] <= g)
		{
			if (vis[i][0])
			{
				Ans = min(Ans, (g + r) * ans[i] + d[m] - d[i]);
				//dbg(i);
				//dbg((g + r) * ans[i] + d[m] - d[i]);
			}
		}
		//if (i == m && vis[i][0])
		//	Ans = min(Ans, (g + r) * ans[i] - r);
	}
	if (Ans == oo) cout << "-1\n";
	else cout << Ans << '\n';
}

main()
{
	input();
	solve();
}