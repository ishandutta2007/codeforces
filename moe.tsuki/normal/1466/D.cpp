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

vi E[123456];
int w[123456];

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
		F1 (i, n) E[i].clear();
		F1 (i, n) cin >> w[i];
		F1 (i, n - 1)
		{
			int u, v;
			cin >> u >> v;
			E[u].pb(v);
			E[v].pb(u);
		}
		vi v;
		F1 (i, n)
			F1 (j, E[i].size() - 1) v.pb(w[i]);
		sort(all(v));
		reverse(all(v));
		//F (i, v.size())
		//	if (i) v[i] += v[i - 1];
		int cur = 0;
		//dbg(v);
		F1 (i, n) cur += w[i];
		cout << cur;
		F (i, n - 2)
		{
			cur += v[i];
			cout << ' ' << cur; 
		}
		cout << '\n';
	}
}

main()
{
	input();
	solve();
}