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
int a[123456];
int ans[123456];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void solve()
{
	while (t --> 0)
	{
		int n, m, x; cin >> n >> m >> x;
		F1 (i, n) cin >> a[i];
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		F1 (i, m) pq.push(mp(0, i));
		F1 (i, n)
		{
			auto x = pq.top();
			pq.pop();
			ans[i] = x.se;
			pq.push(mp(x.fi + a[i], x.se));
		}
		cout << "YES\n";
		F1 (i, n) cout << ans[i] << ' ';
		cout << '\n';
	}
}

main()
{
	input();
	solve();
}