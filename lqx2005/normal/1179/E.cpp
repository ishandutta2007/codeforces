#include <bits/stdc++.h>
#define cp pair<db, db>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1000 + 10;
const ll oo = 1e18;
int n, vis[N];
vector<int> ord;
ll L, l[N], r[N];
map<ll, ll> f[N];
ll ask(int i, ll x) {
	if(f[i].count(x)) return f[i][x];
	cout << "? " << i <<" " << x << endl;
	cin >> f[i][x];
	return f[i][x];
}
void solve(ll l, ll r, vector<int> cur) {
	if(cur.empty()) return;
	if(l + 1 >= r) {
		sort(cur.begin(), cur.end(), [&](int x, int y) {
			return ask(x, r) - ask(x, l) > ask(y, r) - ask(y, l);
		});
		ord.insert(ord.end(), cur.begin(), cur.end());
		return;
	}
	ll mid = (l + r) / 2;
	vector<int> lcur, rcur;
	for(int i : cur) {
		if(ask(i, r) - ask(i, mid) >= ask(i, mid) - ask(i, l)) {
			rcur.push_back(i);
		} else {
			lcur.push_back(i);
		}
	}
	solve(l, mid, lcur), solve(mid, r, rcur);
	return;
}

ll find(int i, ll s, ll x) {
	ll l = s, r = 1e18, t = 1e18;
	while(l <= r) {
		ll mid = (l + r) / 2;
		if(ask(i, mid) - ask(i, s) >= x) t = mid, r = mid - 1;
		else l = mid + 1;
	}
	return t;
}

int main() {
	cin >> n >> L;
	if(n * n * 64 <= 2e5) {
		ll now = 0;
		for(int i = 1; i <= n; i++) {
			ll pos = 2e18;
			int id = -1;
			for(int j = 1; j <= n; j++) {
				if(vis[j]) continue;
				ll x = find(j, now, L / n);
				if(x < pos) {
					pos = x;
					id = j;
				}
			}
			l[id] = now, r[id] = pos;
			vis[id] = 1;
			now = pos;
		}
		cout << "! " << endl;
		for(int i = 1; i <= n; i++) cout << l[i] <<" " << r[i] << endl;
		return 0;
	}
	vector<int> cur;
	for(int i = 1; i <= n; i++) cur.push_back(i);
	solve(0, 1e18, cur);
	ll now = 0;
	for(int i = 0; i < n; i++) {
		int x = ord[i];
		l[x] = now, r[x] = find(x, now, L / n);
		now = r[x];
	}
	cout << "! " << endl;
	for(int i = 1; i <= n; i++) cout << l[i] <<" " << r[i] << endl;
	return 0;
}