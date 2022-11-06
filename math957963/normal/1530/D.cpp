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



int main() {
	int t;
	int n, k, x;
	int a[N];
	int b[N];
	int c[N];
	vi d;
	vi e;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		k = 0;
		rep(i, n) {
			a[i] = -1;
			b[i] = -1;
			cin >> c[i];
			c[i]--;
		}
		rep(i, n) {
			if (b[c[i]] == -1) {
				a[i] = c[i];
				b[c[i]] = i;
				k++;
			}
			else x = i;
		}
		if ((k == n - 1) && (b[x] == -1)) {
			a[x] = c[x];
			a[b[c[x]]] = x;
		}
		else {
			d.clear();
			e.clear();
			rep(i, n)if (a[i] == -1)d.pb(i);
			rep(i, n)if (b[i] == -1)e.pb(i);
			x = d.size();
			rep(i, x) {
				if (i < (x - 1)) {
					a[d[i]] = e[i];
					if (d[i] == e[i]) {
						a[d[i]] = e[i + 1];
						a[d[i + 1]] = e[i];
						i++;
					}
				}
				else {
					a[d[i]] = e[i];
					if (d[i] == e[i])swap(a[d[i - 1]], a[d[i]]);
				}

			}
		}
		cout << k << endl;
		rep(i, n - 1)cout << a[i] + 1 << " ";
		cout << a[n - 1] + 1 << endl;
	}
	return 0;
}