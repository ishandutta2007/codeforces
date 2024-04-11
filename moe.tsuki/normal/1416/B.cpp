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
const int maxn = 12345;
int a[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

vector<pair<pii, int> > ans;

void solve()
{
	while (t --> 0)
	{
		int n; cin >> n;
		F1 (i, n) cin >> a[i];
		int sum = 0;
		F1 (i, n) sum += a[i];
		if (sum % n) 
		{
			cout << "-1\n";
			continue;
		}
		ans.clear();
		sum /= n;
		F1 (i, n)
		{
			if (a[i] % i) 
			{
				ans.pb(mp(mp(1ll, i), i - a[i] % i));
				a[i] += i - a[i] % i;
			}
			ans.pb(mp(mp(i, 1ll), a[i] / i));
		}
		F1 (i, n)
			ans.pb(mp(mp(1ll, i), sum));
		cout << ans.size() << '\n';
		for (auto x : ans)
			cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se << '\n';
	}
}

main()
{
	input();
	solve();
}