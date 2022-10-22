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

const int maxv = 1234567, maxn = 567899, oo = 1e17;
int n, x, y, a[maxn];

vi p, v;
int si[maxv], sum[maxn];

pii numin(int q, int p)
{
	//dbgg(q); dbg(p);
	if (p < q) return mp(0, 0);
	auto qpos = lower_bound(all(v), q);
	auto ppos = upper_bound(all(v), p);
	if (qpos == v.end()) return mp(0,0);
	int l = qpos - v.begin();
	int r = ppos - v.begin() - 1;
	if (l > r) return mp(0, 0);
	return mp(r - l + 1, sum[r + 1] - sum[l - 1 + 1]);
}

void build()
{
	for (int i = 2; i < maxv; ++i)
	{
		if (!si[i]) p.pb(i);
		for (int j = i; j < maxv; j += i) si[j] = true;
	}
}

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	build(); //cout << p;
	cin >> n >> x >> y;
	F1 (i, n) cin >> a[i];
}

void solve()
{
	int mx = 0;
	F1 (i, n) v.pb(a[i]);
	F1 (i, n) mx = max(mx, a[i]);
	sort(all(v));
	
	F (i, v.size()) sum[i + 1] = sum[i] + v[i];
	
	int ANS = oo;
	for (int cur : p)
	{
		int ans = 0;
		for (int i = cur; i < mx + cur; i += cur)
		{
		//dbgg(cur); dbg(i);
			pii toadd = numin(max(i - (x / y), i - cur + 1), i - 1);
			ans += (toadd.first * i - toadd.second) * y;
			pii todel = numin(i - cur + 1, i - (x / y) - 1);
			ans += todel.first * x;
			
			// cout << toadd.fi << ' ' << toadd.se << '\n';
			//cout << todel.fi << ' ' << todel.se << '\n';
		}
		ANS = min(ANS, ans);
		//cout << ans << '\n';
		//MEOW;
	}
	cout << ANS << '\n';
}

main()
{
	input();
	solve();
}