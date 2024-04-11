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

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

const int maxn = 234567;
int l[maxn], r[maxn];
int a[maxn], b[maxn];

void solve()
{
	while (t --> 0)
	{
		int n, q; cin >> n >> q;
		string s, t;
		cin >> s >> t;
		F1 (i, q) cin >> l[i] >> r[i];
		F1 (i, n) if (s[i - 1] == '1') a[i] = 1; else a[i] = 0;
		bool ok = true;
		set<pii> one;
		F1 (i, n) if (t[i - 1] == '1') one.insert(mp(i, i));
		for (int i = q; i >= 1; --i)
		{
			int cnt = 0;
			while (one.lower_bound(mp(l[i], l[i])) != one.end()
			    && one.lower_bound(mp(l[i], l[i])) -> fi <= r[i])
			{
				auto cur = *one.lower_bound(mp(l[i], l[i]));
				one.erase(one.lower_bound(mp(l[i], l[i])));
				if (cur.se > r[i])
				{
					one.insert(mp(r[i] + 1, cur.se));
					cur.se = r[i];
				}
				cnt += cur.se - cur.fi + 1;
			}
			if (one.size())
			{
				auto ptr = one.lower_bound(mp(l[i], l[i]));
				if (ptr != one.begin())
				{
					--ptr;
					auto cur = *ptr;
					one.erase(ptr);
					if (cur.se > r[i])
					{
						cnt += r[i] - l[i] + 1;
						one.insert(mp(cur.fi, l[i] - 1));
						one.insert(mp(r[i] + 1, cur.se));
					} else 
					{
						if (cur.se >= l[i])
						{
							cnt += cur.se - l[i] + 1;
							cur.se = l[i] - 1;
						}
						if (cur.fi >= 1 && cur.fi <= cur.se)
							one.insert(cur);
					}
				}
			}
			int nxt;
			if (cnt < r[i] - l[i] + 1 - cnt) nxt = 0;
			else if (cnt > r[i] - l[i] + 1 - cnt) nxt = 1;
			else nxt = -1;
			if (nxt == -1)
			{
				ok = false;
				break;
			}
			if (nxt == 1)
				one.insert(mp(l[i], r[i]));
		}
		F1 (i, n) b[i] = 0;
		for (auto x = one.begin(); x != one.end(); ++x)
		{
			for (int i = x -> fi; i <= x -> se; ++i)
				b[i] = 1;
		}
		F1 (i, n) if (a[i] != b[i]) ok = false;
 		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}

main()
{
	input();
	solve();
}