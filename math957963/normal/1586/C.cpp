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

vector<string>a;
vector<int>b;

int main() {
	int n, m, s;
	string str;
	cin >> n >> m;
	rep(i, n) {
		cin >> str;
		a.pb(str);
	}
	s = 0;
	b.pb(0);
	rep(j, m - 1) {
		rep(i, n - 1) {
			if ((a[i + 1][j] == 'X') && (a[i][j + 1] == 'X'))s++;
		}
		b.pb(s);
	}
	cin >> s;
	rep(ss, s) {
		cin >> n >> m;
		if (b[n - 1] != b[m - 1])cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}