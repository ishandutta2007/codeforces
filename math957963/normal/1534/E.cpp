#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 410000
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



int main() {
	int n, k, d, m, x, ans;
	int sz;
	vector<int>b, c;
	bool used[510];
	vector<vector<int> >a;
	bool flag = false;
	int idx;
	ans = 0;
	cin >> n >> k;
	sz = k;
	if ((n % 2 == 0) && ((k % 2 == 1)) && ((2 * k) > n)) {
		flag = true;
		k = n - k;
	}
	if (n%k == 0) {
		d = n / k;
		idx = 0;
		rep(j, d) {
			b.clear();
			rep(i, k) {
				b.pb(idx);
				idx++;
			}
			if (flag) {
				rep(j, n)used[j] = false;
				rep(j, k)used[b[j]] = true;
				b.clear();
				rep(j, n) {
					if (!used[j])b.pb(j);
				}
			}
			cout << "?";
			rep(j, sz)cout << " " << b[j] + 1;
			cout << endl;
			cout.flush();
			cin >> x;
			ans ^= x;
		}
		cout << "! " << ans << endl;
		cout.flush();
		return 0;

	}
	if (n % 2 == 1) {
		if (k % 2 == 1) {
			d = (n - 1) / k;
			d++;
			if (d % 2 == 0)d++;
			m = ((k*d) - n) / 2;
		}
		else {
			cout << -1 << endl;
			cout.flush();
			return 0;
		}
	}
	else {
		if (k % 2 == 1) {
			d = (n - 1) / k;
			d++;
			if (d % 2 == 1)d++;
			if (d == 2)d += 2;
			m = ((k*d) - n) / 2;
		}
		else {
			d = (n - 1) / k;
			d++;
			if (d == 2)d++;
			m = ((k*d) - n) / 2;
		}
	}
	idx = m;
	rep(i, d) {
		b.clear();
		if (i <= 2) {
			rep(j, m) {
				b.pb(j);
			}
			rep(j, k - m) {
				b.pb(idx);
				idx++;
			}
		}
		else {
			rep(j, k) {
				b.pb(idx);
				idx++;
			}
		}
		if (flag) {
			rep(j, n)used[j] = false;
			rep(j, k)used[b[j]] = true;
			b.clear();
			rep(j, n) {
				if (!used[j])b.pb(j);
			}
		}
		cout << "?";
		rep(j, sz)cout << " " << b[j]+1;
		cout << endl;
		cout.flush();
		cin >> x;
		ans ^= x;
	}
	cout << "! " << ans << endl;
	cout.flush();
	return 0;
}