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

const int maxl = 20, maxn = 456789;
int q;
int anc[maxn][maxl];
int ma[maxn][maxl];
int fir[maxn][maxl];
int sum[maxn][maxl];
int dep[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> q;
}

void solve()
{
	int lastans = 0, cnt = 1;
	F (i, maxl) anc[1][i] = 1;
	F (i, maxl) ma[1][i] = 0;
	while (q --> 0)
	{
		int c, R, W;
		cin >> c >> R >> W;
		R ^= lastans; W ^= lastans;
	
		//dbgg(c); dbgg(R); dbg(W);
		
		if (c == 1)
		{
			anc[++cnt][0] = R;
			ma[cnt][0] = W;
			F1 (i, maxl - 1)
				anc[cnt][i] = anc[anc[cnt][i - 1]][i - 1];
			F1 (i, maxl - 1)
				ma[cnt][i] = max(ma[cnt][i - 1], ma[anc[cnt][i - 1]][i - 1]);
			int d = 20;
			int cur = anc[cnt][0];
			
			//dbg(cnt); dbg(anc[cnt][0]);
			
			while (d --> 0)
			{
				if (ma[cur][d] < ma[cnt][0])
					cur = anc[cur][d];
			}
			if (cur == anc[cnt][0]) fir[cnt][0] = cur;
			else fir[cnt][0] = cur;
			
			
			
			if (fir[cnt][0] == 1 && ma[cnt][0] > 0) 
			{
				dep[cnt] = 0;
				fir[cnt][0] = cnt;
			}
			else dep[cnt] = dep[fir[cnt][0]] + 1;
			
			//dbg(cnt);dbg(cur);dbg(fir[cnt][0]);
			//dbg(dep[cnt]);
			
			F1 (i, maxl - 1)
				fir[cnt][i] = fir[fir[cnt][i - 1]][i - 1];
			sum[cnt][0] = ma[fir[cnt][0]][0];
			F1 (i, maxl - 1)
				sum[cnt][i] = sum[cnt][i - 1] + sum[fir[cnt][i - 1]][i - 1];
		} else
		{
			int ans = 0;
			int r = R;
			if (ma[R][0] > W) 
			{
				//dbg("haha");
				//dbg(R);
				//dbg(ma[R][0]);
				//dbg(W);
				
			}
			else
			{
				//dbg("fuck");
				ans = 1;
				W -= ma[R][0];
				int d = 20;
				//R = fir[R][0];
				//dbg(R);
				while (d --> 0)
				{
					if (sum[R][d] <= W)
					{
						W -= sum[R][d];
						R = fir[R][d];

						ans += 1 << d;
					}
				}
				if (fir[R][0] == R)
					ans = dep[r] + 1;
				//dbg(ans);
				
			}
			cout << ans << '\n';
			lastans = ans;
			
			//dbg(lastans);
		}
	}
}

main()
{
	input();
	solve();
}