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

const int maxk = 23;
int k;
vi a[maxk];
int ssum;
map<int, int> m;
pii ans[maxk];
int sum[maxk];
bool pri[65567];
pii from[65567];
bool ok[65567];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> k;
	F1 (i, k)
	{
		int n; cin >> n;
		int x;
		while (n --> 0)
		{
			cin >> x; a[i].pb(x);
		}
	}
}

int gao(int str, int cur, int need, int last, int out = 0)
{
	//dbg(last); dbg(need); dbg(str); dbg(cur);
	if (m.find(need) == m.end()) return 0;
	int now = m[need];
	if (out) { ans[now] = mp(last, need); }
	if ((1 << now) & cur)
	{
		if (str == now) 
			return cur;
		else return 0;
	} else
	{
		return gao(str, cur | (1 << now), ssum - (sum[now] - need), now, out);
	}
	return 0;
}

void dfs(int cur)
{
	if (pri[cur])
	{
		//dbg("gertregergregergreewr");
		gao(from[cur].fi, 1 << from[cur].fi, ssum - (sum[from[cur].fi] - from[cur].se), from[cur].fi, 1);
	} else
	{
		dfs(from[cur].fi);
		dfs(from[cur].se);
	}
}

void solve()
{
	F1 (i, k)
	{
		sum[i] = 0;
		for (auto x : a[i]) 
		{
			sum[i] += x;
			m[x] = i;
		}
	}
	F1 (i, k) ssum += sum[i];
	if (ssum % k)
	{
		cout << "No\n"; return;
	}
	ssum /= k;
	
	F1 (i, k)
		for (auto x : a[i])
		{
			int cur = gao(i, 1 << i, ssum - (sum[i] - x), 0);
			if (!cur) continue;
			int su = 0;
			F1 (j, k) if ((1 << j) & cur) su += sum[j] - ssum;
			if (su != 0) continue;
			pri[cur / 2] = true;
			from[cur / 2] = mp(i, x);
			ok[cur / 2] = true;
		}
	for (int i = 1; i < 1 << k; ++i)
	{
		if (!ok[i])
		{
			int j = i;
			while (j = ((j - 1) & i))
			{
				if (ok[j] && ok[i ^ j])
				{
					ok[i] = true;
					from[i] = mp(j, i ^ j);
					break;
				}
			}
		}
	}
	F1 (i, (1 << k)) if (ok[i]) dbg(i);
	if (!ok[(1 << k) - 1]) { cout << "No\n"; return; }
	cout << "Yes\n";
	dfs((1 << k) - 1);
	F1 (i, k) cout << ans[i].se << ' ' << ans[i].fi << '\n';
}

main()
{
	input();
	solve();
}