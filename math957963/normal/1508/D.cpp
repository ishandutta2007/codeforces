#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
#define MOD 1000000007  //998244353
#define EPS (long double)0.000000001
#define PI (long double)3.1415926536
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
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

vector<long double>ax, ay;
vector<pair<long double, int> >b;
int n;
int p[N];
int lef[N];
int righ[N];
bool used[N];
int sz;
long double x, y;
int cent;
int xx;
vector<pii>ans;

void dfs(int cur, int end) {
	bool le = false;
	bool ri = false;
	if (!used[lef[cur]]) {
		xx = lef[cur];
		while (!used[xx]) {
			used[xx] = true;
			xx = p[xx];
		}
		dfs(lef[cur], lef[cur]);
		le = true;
	}
	if (!used[righ[cur]]) {
		xx = righ[cur];
		while (!used[xx]) {
			used[xx] = true;
			xx = p[xx];
		}
		dfs(righ[cur], righ[cur]);
		ri = true;
	}
	ans.pb({ cent,cur });
	if (ri)ans.pb({ cur,righ[cur] });
	if (le)ans.pb({ cur,lef[cur] });
	if (p[cur] == end)return;
	dfs(p[cur], end);
	return;
}



int main() {
	cin >> n;
	rep(i, n)used[i] = false;
	cent = -1;
	rep(i, n) {
		cin >> x >> y;
		cin >> p[i];
		p[i]--;
		if (p[i] != i) {
			if (cent == -1)cent = i;
		}
		else used[i] = true;
		ax.pb(x);
		ay.pb(y);
	}
	if (cent == -1) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, n) {
		if ((!used[i]) && (i != cent)) {
			x = ax[i] - ax[cent];
			y = ay[i] - ay[cent];
			if (abs(x) < EPS) {
				if (y > 0)b.pb({ PI / (2.0),i });
				else b.pb({ PI*(3.0) / (2.0),i });
			}
			else if (abs(y) < EPS) {
				if (x > 0)b.pb({ 0.0,i });
				else b.pb({ PI,i });
			}
			else {
				if ((x > 0) && (y > 0))b.pb({ atan(y / x),i });
				if ((x < 0) && (y > 0))b.pb({ atan(y / x)+PI,i });
				if ((x < 0) && (y < 0))b.pb({ atan(y / x)+PI,i });
				if ((x > 0) && (y < 0))b.pb({ atan(y / x) + (PI*(2.0)),i });
			}
		}
	}
	sort(all(b));
	sz = b.size();
	used[N - 1] = true;
	rep(i, n) {
		lef[i] = N - 1;
		righ[i] = N - 1;
	}
	rep(i, sz - 1) {
		if ((b[i + 1].first - b[i].first) < PI) {
			lef[b[i].second] = b[i + 1].second;
			righ[b[i + 1].second] = b[i].second;
		}
	}
	if ((b[sz - 1].first - b[0].first) > PI) {
		lef[b[sz - 1].second] = b[0].second;
		righ[b[0].second] = b[sz - 1].second;
	}
	xx = cent;
	while (!used[xx]) {
		used[xx] = true;
		xx = p[xx];
	}
	used[N - 1] = true;
	dfs(p[cent], cent);
	sz = ans.size();
	cout << sz << endl;
	rep(i, sz) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}

	return 0;
}