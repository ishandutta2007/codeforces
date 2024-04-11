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


int n;
vi v;	
vi a[123];
vector<pii> ans;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
}

void gao(vi &v)
{
	for (int i = 1; i < v.size(); i <<= 1)
	{
		for (int j = 0; j < v.size(); ++j)
			if (j & i)
				ans.pb(mp(v[j], v[j ^ i]));
	}
}

#define lowbit(x) (x & (-x))

void solve()
{
	int m = n;
	while (m)
	{
		v.pb(lowbit(m));
		m -= lowbit(m);
	}
	reverse(all(v));
	int cur = v.size() - 1;
	int cnt = 0;
	F (i, v.size())
		F (j, v[i])
			a[i].pb(++cnt);
	F (i, v.size())
		gao(a[i]);
	while (cur >= 2)
	{
		if (v[cur] == v[cur - 1])
		{
			F (i, v[cur])
				ans.pb(mp(a[cur][i], a[cur - 1][i]));
			F (i, v[cur])
				a[cur - 1].pb(a[cur][i]);
			--cur;
			v[cur] *= 2;
			continue;
		} else
		{
			F (i, v[cur])
				ans.pb(mp(a[0][v[0] - i - 1], a[cur][i]));
			F (i, v[cur])
				a[cur].pb(a[0][v[0] - i - 1]);
			v[0] -= v[cur];
			v[cur] *= 2;
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x.fi << ' ' << x.se << '\n';
}

main()
{
	input();
	solve();
}