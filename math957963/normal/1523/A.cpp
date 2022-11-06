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
	int n, m;
	char a[1010];
	int l[1010];
	int r[1010];
	int x, y;
	cin >> t;
	rep(tt, t) {
		cin >> n >> m;
		rep(i, 1010)a[i] = 0;
		cin >> a;
		x = -MOD - N;
		rep(i, n) {
			if (a[i] == '1')x = i;
			l[i] = x;
		}
		x = MOD + N;
		rep3(i, n - 1, 0) {
			if (a[i] == '1')x = i;
			r[i] = x;
		}
		rep(i, n) {
			if (a[i] == '0') {
				if (((i- l[i] <= m) || (r[i] - i <= m)) && ((r[i] - i) != (i - l[i])))a[i] = '1';
			}
		}
		cout << a << endl;
	}
	return 0;
}