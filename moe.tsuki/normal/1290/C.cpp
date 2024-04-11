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

const int maxn = 345678;
string s;
int n, k;
vi con[maxn];
int a[maxn];
int par[maxn];
int dis[maxn];
int lev[maxn][2];
int fix[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	cin >> s;
	F1 (i, k)
	{
		int c; cin >> c;
		F1 (j, c)
		{
			int x; cin >> x;
			con[x].pb(i);
		}
	}
}

int root(int cur)
{
	if (par[cur] == cur) return cur;
	int r = root(par[cur]);
	dis[cur] ^= dis[par[cur]];
	return par[cur] = r;
}

void solve()
{
	F1 (i, n) a[i] = s[i - 1] - '0';
	F1 (i, k) par[i] = i;
	F1 (i, k) dis[i] = 0;
	F1 (i, k)
	{
		lev[i][0] = 1;
		lev[i][1] = 0;
	}
	F1 (i, k) fix[i] = -1;
	int ans = 0;
	//F1 (i, n) dbg(a[i]);
	F1 (i, n)
	{
		//dbgg("NOW AT"); dbg(i);
		//F1 (j, k) dbg(par[j]);
		
		if (con[i].size() == 1)
		{
			int cur = con[i][0];
			int cho = 0;
			if (a[i] == 0) cho = 1;
			int r = root(cur);
			
			if (fix[r] != -1) ans -= lev[r][fix[r]];
			else ans -= min(lev[r][0], lev[r][1]);
			fix[r] = dis[cur] ^ cho ^ 1;
			ans += lev[r][fix[r]];
		} else if (con[i].size() == 2)
		{
			int p = con[i][0], q = con[i][1];
			int r = root(p), s = root(q);
			//dbgg(p); dbg(q);
			//dbgg(r); dbg(s);
			if (r != s)
			{
				int prt = 1;
				if (a[i] == 1) prt = 0;//dbg(prt);
				prt ^= dis[p] ^ dis[q];
				
				//dbgg(dis[p]); dbg(dis[q]);
				if (fix[r] != -1) ans -= lev[r][fix[r]];
				else ans -= min(lev[r][0], lev[r][1]);
				
				if (fix[s] != -1) ans -= lev[s][fix[s]];
				else ans -= min(lev[s][0], lev[s][1]);
				
				par[r] = s;
				dis[r] = prt;
				
				lev[s][0] += lev[r][0 ^ prt];
				lev[s][1] += lev[r][1 ^ prt];
				//dbgg(fix[s]); dbgg(fix[r]); dbg(prt);
				if (fix[r] != -1) 
				{
					assert(fix[s] == -1 || fix[s] == fix[r] ^ prt);
					fix[s] = fix[r] ^ prt; 
				}
				if (fix[s] != -1) ans += lev[s][fix[s]];
				else ans += min(lev[s][0], lev[s][1]);
			}
			
		}
		//dbg(i);
		//1 (j, k) dbg(fix[j]);
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}