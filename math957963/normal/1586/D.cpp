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
	int n;
	int x;
	int a[110];
	cin >> n;
	a[n - 1] = 1;
	rep(i, n - 1) {
		cout << "?";
		rep(j, n - 1)cout << " " << 1;
		cout << " " << i + 2 << endl;
		cout.flush();
		cin >> x;
		if (x == 0) {
			a[n - 1] = n - i;
			break;
		}
	}
	rep(i, n) {
		if ((i + 1) != a[n - 1]) {
			cout << "?";
			rep(j, n - 1)cout << " " << a[n - 1];
			cout << " " << i + 1 << endl;
			cout.flush();
			cin >> x;
			a[x - 1] = i + 1;
		}
	}
	cout << "!";
	rep(i, n)cout << " " << a[i];
	cout << endl;

	return 0;
}