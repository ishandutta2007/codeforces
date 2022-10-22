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

const int maxn = 123456;
int t;
int a[maxn];
int cnt[maxn];

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
		F1 (i, n) cin >> a[i];
		F1 (i, n) if (a[i] == a[i - 1]) 
		{
			cnt[a[i]] += 2;
		}
		//if (a[1] != a[2])
			++cnt[a[1]];
		//if (a[n - 1] != a[n] && n != 2)
			++cnt[a[n]];
		int mx = 0, fu, ans = 0;
		F1 (i, n)	
		{
			ans += cnt[i];
			if (mx < cnt[i])
			{
				mx = cnt[i];
				fu = i;
			}
		}
		F1 (i, n) if (a[i] == a[i - 1]) 
		{
			cnt[a[i]] -= 2;
		}
		//if (a[1] != a[2])
			--cnt[a[1]];
		//if (a[n - 1] != a[n] && n != 2)
			--cnt[a[n]];
		//dbg(ans);
		//dbg(mx);
		if (ans <= 2) cout << ans / 2 - 1 << '\n';
		else
		{
			if (mx * 2 - ans < 4) cout << ans / 2 - 1 << '\n';
			else
			{
				int need = (mx * 2 - ans) / 2 - 1;
				ans += need * 2;
				F1 (i, n) if (a[i] != a[i - 1]) 
				{
					if (a[i] != fu && a[i - 1] != fu && i != 1)
						--need;
				}
				if (need > 0) cout << "-1\n";
				else cout << ans / 2 - 1 << '\n';
			}
		}
	}
}

main()
{
	input();
	solve();
}