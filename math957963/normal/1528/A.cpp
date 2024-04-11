#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

ll a[N];
ll b[N];
bool used[N];
vi e[N];

pll dfs(int k) {
	used[k] = true;
	pll p;
	pll re = { 0,0 };
	int sz = e[k].size();
	rep(i, sz) {
		if (!used[e[k][i]]) {
			p = dfs(e[k][i]);
			re.first += max(p.first + abs(a[k] - a[e[k][i]]), p.second + abs(a[k] - b[e[k][i]]));
			re.second += max(p.first + abs(b[k] - a[e[k][i]]), p.second + abs(b[k] - b[e[k][i]]));
		}
	}
	return re;
}



int main() {
	int t;
	int n;
	int x, y;
	pll ans;
	ll z;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n)cin >> a[i] >> b[i];
		rep(i, n - 1) {
			cin >> x >> y;
			e[x - 1].pb(y - 1);
			e[y - 1].pb(x - 1);
		}
		rep(i, n)used[i] = false;
		ans = dfs(0);
		z = max(ans.first, ans.second);
		cout << z << endl;
		rep(i, n)e[i].clear();
	}


	return 0;
}