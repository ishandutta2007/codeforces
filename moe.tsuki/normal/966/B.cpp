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
int n, x1, x2;
vector<pii> c;
int d[maxn];
pii pm[maxn], sm[maxn];
int pre[maxn];
int len[maxn];
pii suf[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x1 >> x2;
	F1 (i, n) 
	{
		int x; cin >> x;
		c.pb(mp(x, i));
	}
}

void solve()
{
	sort(all(c));
	
	//cout << c;
	F (i, c.size())
	{
		d[i] = (n - i) * c[i].fi;
	}
	
	for (int i = c.size() - 1; i >= 0; --i)
	{
		if (i == c.size() - 1)
		{
			sm[i] = mp(d[i], i);
			continue;
		}
		if (d[i] >= sm[i + 1].fi)
		{
			sm[i] = mp(d[i], i);
		} else sm[i] = sm[i + 1];
	}
	
	
	for (int i = 0; i < c.size(); ++i)
	{
		int l = i, r = l - 1 + ((x1 + c[i].fi - 1) / c[i].fi);
		len[i] = r - l + 1;
		if (r >= n) { len[i] = maxn; continue; }
		if (i != c.size() - 1)
		{
			//dbg(sm[i + 1].fi);
			if (sm[r + 1].fi >= x2)
			{
				//dbg(l);
				int k1 = r - l + 1;
				int start = sm[r + 1].se;
				int k2 = n - start;
				cout << "Yes\n";
				cout << k1 << ' ' << k2 << '\n';
				for (int t = l; t <= r; ++t)
					cout << c[t].se << ' ';
				cout << '\n';
				for (int t = start; t < n; ++t)
					cout << c[t].se << ' ';
				cout << '\n';
				//dbg("haha");
				return;
				
			}
		}
	}
	
	for (int i = c.size() - 1; i >= 0; --i)
	{
		if (i == c.size() - 1)
		{
			suf[i] = mp(len[i], i);
			continue;
		}
		if (len[i] <= suf[i + 1].fi)
		{
			suf[i] = mp(len[i], i);
		} else suf[i] = suf[i + 1];
	}
	
	for (int i = 0; i < c.size() - 1; ++i)
	{
		int l = i, r = l - 1 + ((x2 + c[i].fi - 1) / c[i].fi);
		int need = r - l + 1;
		int lft = n - l - need;
		/*dbgg(i);
		dbg(need);
		dbg(lft);
		dbg(suf[3]);*/
		if (suf[i + 1].fi <= lft)
		{
			cout << "Yes\n";
			int fu = suf[i + 1].fi;
			int id = suf[i + 1].se;
			int k1 = n - l - fu;
			int k2 = fu;
			cout << k2 << ' ' << k1 << '\n';
			
			for (int t = id; t < id + fu; ++t)
				cout << c[t].se << ' ';
			cout << '\n';
			
			for (int t = i; t < id; ++t)
				cout << c[t].se << ' ';
			for (int t = id + fu; t < n; ++t)
				cout << c[t].se << ' ';
			cout << '\n'; 	
				
			
			return;
		}
	}
	cout << "No\n";
}

main()
{
	input();
	solve();
}