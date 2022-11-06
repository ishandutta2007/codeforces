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
	int n;
	int x, y;
	int c = 95;
	int l, r, m;
	int a[N];
	cin >> n;
	l = 0;
	r = n;
	while ((r-l)>c) {
		m = (l + r) / 2;
		cout << "? " << m + 1 << endl;
		cout.flush();
		cin >> x;
		cout << "? " << m + 2 << endl;
		cout.flush();
		cin >> y;

		c -= 2;
		if (x > y)l = m;
		else r = m + 2;
	}
	l = max(l - 1, 0);
	r = min(r + 1, n - 1);
	rep(i, n + 2)a[i] = -1;
	a[0] = MOD;
	a[n + 1] = MOD;
	a[n + 2] = MOD;
	rep2(i, l, r) {
		cout << "? " << i + 1 << endl;
		cout.flush();
		cin >> x;
		a[i + 1] = x;
		if ((a[i] > a[i + 1]) && (a[i + 1] < a[i + 2])) {
			cout << "! " << i + 1 << endl;
			cout.flush();
			return 0;
		}
		if (i > 0) {
			if ((a[i - 1] > a[i]) && (a[i] < a[i + 1])) {
				cout << "! " << i << endl;
				cout.flush();
				return 0;
			}
		}
	}
	return 0;
}