#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N (1<<18)
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



int main() {
	int a, b;
	int x, y, z, t;
	cin >> t;
	rep(tt, t) {
		cin >> a >> b;
		if ((a + b) % 2 == 0) {
			x = (a + b) / 2;
			y = max(a, b) - x;
			z = a + b - y;
			x = (z - y + 2) / 2;
			cout << x << endl;
			for (int i = y; i < z; i += 2)cout << i << " ";
			cout << z << endl;
		}
		else {
			x = (a + b + 1) / 2;
			y = max(a, b) - x;
			z = a + b - y;
			x = z - y + 1;
			cout << x << endl;
			for (int i = y; i < z; i ++)cout << i << " ";
			cout << z << endl;
		}
	}



	return 0;
}