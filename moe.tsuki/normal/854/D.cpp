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
	s << "[ "; cout << c.fi << ' ' << c.se << "]\n";
	return s;
}


const int maxn = 123456, maxd = 1234567, oo = 1e15;
int n, m, k, pre[maxd], suf[maxd];
int used, cur, vis[maxn], mi[maxn];
vector<pair<int, pii> > in, out;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	int d, f, t, c;
	F1 (i, m)
	{
		cin >> d >> f >> t >> c;
		if (f == 0) in.pb(mp(-d, mp(t, c)));
		if (t == 0) out.pb(mp(d, mp(f, c)));
	}
}

void solve()
{
	sort(all(in)); sort(all(out));
	
	F (i, maxd) pre[i] = suf[i] = oo;
	
	{
		
		for (auto meow : out)
		{
			int day = meow.fi, city = meow.se.fi, cost = meow.se.se;
			if (!vis[city]) 
			{
				++used;
				cur += cost;
				mi[city] = cost;
				vis[city]= true;
			} else
				if (cost < mi[city]) 
				{
					cur -= mi[city] - cost; 
					mi[city] = cost;
				}
			if (used == n) pre[day + 1] = cur;
		}
		
		int last = 0;
		for (int i = 0; i < maxd; ++i)
		{
			if (pre[i] == oo) pre[i] = pre[last];
			else last = i;
		}
	}
	
	{
		used = 0, cur = 0;
		F (i, maxn) vis[i] = mi[i] = 0;
		for (auto meow : in)
		{
			// day * -1 ><
			int day = -meow.fi, city = meow.se.fi, cost = meow.se.se;
			if (!vis[city]) 
			{
				++used;
				cur += cost;
				mi[city] = cost;
				vis[city]= true;
			} else
				if (cost < mi[city]) 
				{
					cur -= mi[city] - cost; 
					mi[city] = cost;
				}
			if (used == n) suf[day - 1] = cur;
		}
		
		int last = maxd - 1;
		for (int i = maxd - 1; i >= 0; --i)
		{
			if (suf[i] == oo) suf[i] = suf[last];
			else last = i;
		}
	}
	
	int ans = oo;
	
	for (int i = 0; i + k - 1 < maxd; ++i) ans = min(ans, pre[i] + suf[i + k - 1]);
	if (ans == oo) cout << -1 << '\n';
	else cout << ans << '\n';
}

main()
{
	input();
	solve();
}