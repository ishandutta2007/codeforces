#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
#define MOD 998244353
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

int p[N];
int d[N];
vector<int>e[N];
int c[N];
bool used[N];
int pt[N];
vector<int>ansa;
vector<vector<int> >ans;


int par(int k) {
	if (p[k] == k)return k;
	return p[k] = par(p[k]);
}

void uni(int x, int y) {
	int px = par(x);
	int py = par(y);
	if (px != py) {
		e[x].pb(y);
		e[y].pb(x);
		if (d[px] < d[py]) {
			p[px] = py;
			d[py] = max(d[py], d[px] + 1);
		}
		else {
			p[py] = px;
			d[px] = max(d[px], d[py] + 1);
		}
	}
}

bool ok;

void dfs(int k, int d,int goal) {
	pt[d] = k;
	used[k] = true;
	if (k == goal) {
		ok = true;
		return;
	}
	int sz = e[k].size();
	rep(i, sz) {
		if (!used[e[k][i]])dfs(e[k][i], d + 1, goal);
		if (ok)return;
	}
	return;
}


int main() {
	rep(i, N) {
		p[i] = i;
		d[i] = 1;
	}
	int n, m, q;
	int x, y, z;
	cin >> n >> m;
	rep(i, m) {
		cin >> x >> y;
		uni(x - 1, y - 1);
	}
	rep(i, n)c[i] = 0;
	cin >> q;
	rep(qq, q) {
		cin >> x >> y;
		rep(i, n)used[i] = false;
		ok = false;
		dfs(x - 1, 0, y - 1);
		c[x - 1]++;
		c[y - 1]++;
		ansa.clear();
		rep(i, n) {
			ansa.pb(pt[i]);
			if (pt[i] == y - 1)break;
		}
		ans.pb(ansa);
	}
	x = 0;
	rep(i, n)if (c[i] % 2 == 1)x++;
	if (x > 0) {
		cout << "NO" << endl;
		cout << (x / 2) << endl;
	}
	else {
		cout << "YES" << endl;
		rep(qq, q) {
			x = ans[qq].size();
			cout << x << endl;
			rep(i, x - 1)cout << ans[qq][i]+1 << " ";
			cout << ans[qq][x - 1]+1 << endl;
		}
	}


	return 0;
}