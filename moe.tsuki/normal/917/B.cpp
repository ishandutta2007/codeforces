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

const int maxf = 345678;
int n, m, vis[maxf], win[maxf];
vector<pair<int, char> > e[maxf];
vi E[maxf];

#define fu(x,y,z) ((z+1)*10201+(x)*101+(y))

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, m)
	{	
		int f, t;
		char k;
		cin >> f >> t >> k;
		e[f].pb(mp(t, k - 'a'));
	}
}

void dfs(int cur)
{
	win[cur] = false;
	vis[cur] = true;
	for (int x : E[cur])
	{
		if (!vis[x]) dfs(x);
		if (!win[x]) win[cur] = true;
	}
}

void solve()
{
	F1 (i, n) 
		F1 (j, n)
			F (k, 26)
				for (auto x : e[i])
					if (x.se >= k) E[fu(i, j, k)].pb(fu(j, x.fi, x.se));
	/*F1 (i, n) 
		F1 (j, n)
			F (k, 26)
			{
				if (!vis[fu(i, j, k)])
					dfs(fu(i, j, k));
			}*/
	F1 (i, n)
	{
		F1 (j, n) 
		{
			if (!vis[fu(i, j, 0)]) dfs(fu(i, j, 0));
			if (win[fu(i, j, 0)]) cout << 'A';
			else cout << 'B';
		}
		cout << '\n';
	}
}

main()
{
	input();
	solve();
}