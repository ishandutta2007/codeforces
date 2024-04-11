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

const int mod = 1000000007;
int t;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

vector<pii> v;
map<int, int> m;

int power(int a, int b)
{
	if (b == 0) return 1;
	int ret = power(a * a % mod, b / 2);
	if (b & 1) ret = ret * a % mod;
	return ret;
}

void solve()
{
	while (t --> 0)
	{
		int n, p;
		cin >> n >> p;
		
		m.clear();
		F1 (i, n) 
		{
			int ki; cin >> ki;
			m[ki]++;
		}
		if (p == 1)
		{
			cout << (n & 1) << '\n';
			continue;
		}
		v.clear();
		for (auto x : m)
			v.pb(x);
		reverse(all(v));
		bool end = false;
		int cur = 0, l = v[v.size() - 1].fi;
		v.pb(mp(0, 0));
		for (auto x : v)
		{
			//dbg(x);
			if (cur != 0)
			{
				if (l - x.fi >= 20)
				{
					end = true;
					cur = cur * power(p, l - x.fi) % mod;
				} else
				{
					F (i, l - x.fi)
					{
						cur = cur * p;
						if (cur > n) end = true;
						cur %= mod;
					}
				}
			}
			l = x.fi;
			if (end == true)
			{
				cur = cur + mod - x.se;
				cur %= mod;
			} else
			{
				if (x.se <= cur) cur -= x.se;
				else cur = (x.se - cur) & 1;
			}
			//dbg(cur);
		}
		cout << cur << '\n';
	}
}

main()
{
	input();
	solve();
}