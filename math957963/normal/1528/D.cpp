#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 1000
#define M (ll)1000000000000000000
#define MOD 998244353
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





int main() {
	ll n, m;
	vector<pll>e[N];
	priority_queue<pll>pq;
	pll p;
	ll d[N];
	bool used[N];
	ll x;
	ll mn;
	ll sz;
	ll y, z;
	cin >> n >> m;
	rep(i, m) {
		cin >> x >> y >> z;
		e[x].pb({ y,z });
	}
	rep(i, n) {
		mn = M;
		sz = e[i].size();
		rep(j, sz) {
			mn = min(mn, e[i][j].second);
		}
		rep(j, n) {
			d[j] = mn + n;
			used[j] = false;
		}
		while (!pq.empty())pq.pop();
		sz = e[i].size();
		rep(j, sz) {
			y = e[i][j].first;
			if (e[i][j].second < d[y]) {
				d[y] = e[i][j].second;
				pq.push({ -d[y],y });
			}
		}
		rep(ii, n) {
			p = pq.top();
			while (used[p.second]) {
				pq.pop();
				p = pq.top();
			}
			x = p.second;
			y = -p.first;
			used[x] = true;
			z = (x + 1) % n;
			if ((y + 1) < d[z]) {
				d[z] = y + 1;
				pq.push({ -d[z],z });
			}
			sz = e[x].size();
			rep(j, sz) {
				z = (y + e[x][j].first) % n;
				if ((y + e[x][j].second) < d[z]) {
					d[z] = y + e[x][j].second;
					pq.push({ -d[z],z });
				}
			}
		}
		d[i] = 0;
		rep(j, n - 1)cout << d[j] << " ";
		cout << d[n - 1] << endl;
	}

	return 0;
}