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

const int maxn = 345678;
int n, k, a[maxn], out[maxn];

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	F1 (i, n) cin >> a[i]; 
}

void solve()
{
	priority_queue<pii, vector<pii> > pq;
  F1 (i, k) pq.push(mp(a[i], i));
	int ans = 0;
	for (int i = k + 1; i <= k + n; ++i)
  {
  	if (i <= n) pq.push(mp(a[i], i));
  	pii meow;
		if (pq.size()) { meow = pq.top(); pq.pop(); }
		ans += meow.fi * (i - meow.se);  
		out[meow.se] = i;
	}
	cout << ans << '\n';
	F1 (i, n) cout << out[i] << ' ';
}

main()
{
	input();
	solve();
}