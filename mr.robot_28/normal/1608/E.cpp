#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
const int N = 1e5 + 100;
const int mod = 998244353;

int n;
int funct1(vector <int> c, int midd, vector <vector <int> >&x, vector <vector <int> > &y) {
	int last = -1e9 - 1;
	int c1 = midd, c2 = midd, c3 = midd;
	int i = 0;
	while (c1 > 0 && i < n) {
		if (c[0] == x[i][2]) {
		    last = x[i][0];
			c1--;
		}
		i++;
	}
	int j = 0;
	int lasty = -1e9 - 1;
	while (c2 > 0 && j < n) {
		if (y[j][0] > last && c[1] == y[j][2]) {
		    lasty = y[j][1];
			c2--;
		}
		j++;
	}
	while (i < n && c3 > 0) {
		if (x[i][0] > last && x[i][1] > lasty && c[2] == x[i][2]) {
			c3--;
		} 
		i++;
	}
	if (c1 == 0 && c2 == 0 && c3 == 0) {
		return 1;
	}
	return 0;
}

int funct(vector <int> c, int midd, vector <vector <int> > &x, vector <vector <int> > &y) {
	int last = -1e9 - 1;
	int c1 = midd, c2 = midd, c3 = midd;
	int i = 0;
	while (c1 > 0 && i < n) {
		if (x[i][2] == c[0]) {
			c1--;
			last = x[i][0];
		}
		i++;
	}
	int last1 = -1e9 - 1;
	while (c2 > 0 && i < n) {
		if (x[i][0] > last && x[i][2] == c[1]) {
			last1 = x[i][0];
			c2--;
		}
		i++;
	}
	while (c3 > 0 && i < n) {
		if (x[i][0] > last1 && x[i][2] == c[2]) {
			c3--;
		}
		i++;
	}
	if (c1 == 0 && c2 == 0 && c3 == 0) {
		return 1;
	}
	if (funct1(c, midd, x, y)) {
		return 1;
	}
	for (i = 0; i < n; i++) {
		x[i][0] = -x[i][0];
		y[i][0] = -y[i][0];
	}
	reverse(x.begin(), x.end());
	if (funct1(c, midd, x, y)) {
	for (i = 0; i < n; i++) {
		x[i][0] = -x[i][0];
		y[i][0] = -y[i][0];
	}
	reverse(x.begin(), x.end());
		return 1;
	}
	for (i = 0; i < n; i++) {
		x[i][0] = -x[i][0];
		y[i][0] = -y[i][0];
	}
	reverse(x.begin(), x.end());
	return 0;
}

bool cmp(vector <int> a, vector <int> b) {
	return a[2] < b[2];
}
signed main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector <vector <int> > x(n, vector <int> (3));
	vector <vector <int> > y(n, vector <int> (3));
	for (int i = 0; i < n; i++) {
		cin >> x[i][0] >> x[i][1] >> x[i][2];
		y[i][2] = x[i][2];
		y[i][0] = x[i][1];
		y[i][1] = x[i][0];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = 0; i < n; i++) {
		swap(y[i][0], y[i][1]);
	}
//	cout << "A\n";
	int l = 0, r = n / 3 + 1;
	while (r - l > 1) {
		int midd = (r + l) / 2;
//		cout << midd << "\n";
		vector <int> c = {1, 2, 3};
		int fl = 0;
		do {
			if (funct(c, midd, x, y)) {
				fl = 1;
			}
			for (int i = 0; i < n; i++) {
				swap(x[i][0], x[i][1]);
				swap(y[i][0], y[i][1]);
			}
			if (funct(c, midd, y, x)) {
				fl = 1;
			}
			for (int i = 0; i < n; i++) {
				swap(x[i][0], x[i][1]);
				swap(y[i][0], y[i][1]);
			}
		} while(next_permutation(c.begin(), c.end()));
		if (fl) {
			l = midd;
		}
		else {
			r = midd;
		}
	}
	cout << l * 3;
	return 0;
}