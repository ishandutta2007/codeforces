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
const int mod = 1000000007;
int po[123];
int hv[67];
int a[567890];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	po[0] = 1;
	F1 (i, 122)
		po[i] = po[i - 1] * 2 % mod;
	//F (i, 123) dbg(po[i]);
	while (t --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		/*F (j, 60)
			F (k, 60)
			{
				F (p, 1)
					F (q, 1)
						F (r, 1)
							
						{
							if ((p & q == 0) || (q | r == 0)) continue;
							int x = 0, y = 0, z = 0;
							F1 (i, n)
							{
								if ((a[i] & (1 << j)) == (1 << j) * p) ++x;
								if ((a[i] & (1 << j)) == (1 << j) * q) ++x;
								if ((a[i] & (1 << j)) == (1 << j) * p) ++x;
							}
						}
			}*/	
		F (j, 60)
		{
			hv[j] = 0;
			F1 (i, n)
				if (a[i] & (1ll << j))
					++hv[j];
			//dbg(hv[j]);
		}
		int ans = 0;
		F1 (i, n)
		{
			int sx = 0;
			F (j, 60)
				if (a[i] & (1ll << j)) sx = (sx + hv[j] * po[j] % mod) % mod;
			F (k, 60)
			{
				int y = hv[k];
				if (a[i] & (1ll << k))
					y = n;
				ans = (ans + (po[k] * sx % mod) * y % mod) % mod;
			}
		}
		cout << ans << '\n';
	}
}

main()
{
	input();
	solve();
}