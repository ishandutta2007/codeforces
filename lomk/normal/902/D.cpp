/*input
1
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}

int a[155], b[155];
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	a[1] = 1; b[0] = -1;
	for (int step = 2; step <= n; step++) {
		if (step % 2 == 0) {
			bool neg = 0;
			for (int i = 0; i <= 150; i++) {
				b[i + 1] += a[i];
				if (b[i + 1] > 1) neg = true;
			}
			if (neg) {
				for (int i = 0; i <= 150; i++)
					b[i + 1] -= a[i];
				for (int i = 0; i <= 150; i++)
					b[i + 1] -= a[i];
			}
		}
		else {
			bool neg = 0;
			for (int i = 0; i <= 150; i++) {
				a[i + 1] += b[i];
				if (a[i + 1] > 1) neg = true;
			}
			if (neg) {
				for (int i = 0; i <= 150; i++)
					a[i + 1] -= b[i];
				for (int i = 0; i <= 150; i++)
					a[i + 1] -= b[i];
			}
		}
	}
	if (a[n] == 0) {
		if (b[n] == -1) for (int i = 0; i <= n; i++) b[i] = -b[i];
		cout << n << endl;
		for (int i = 0; i <= n; i++) cout << b[i] << sp;
		cout << endl;
		if (a[n - 1] == -1) for (int i = 0; i <= n; i++) a[i] = -a[i];
		cout << n - 1 << endl;
		for (int i = 0; i <= n - 1; i++) cout << a[i] << sp;
		cout << endl;
	}
	else {
		if (a[n] == -1) for (int i = 0; i <= n; i++) a[i] = -a[i];
		cout << n << endl;
		for (int i = 0; i <= n; i++) cout << a[i] << sp;
		cout << endl;
		if (b[n - 1] == -1) for (int i = 0; i <= n; i++) b[i] = -b[i];
		cout << n - 1 << endl;
		for (int i = 0; i <= n - 1; i++) cout << b[i] << sp;
		cout << endl;
	}
}