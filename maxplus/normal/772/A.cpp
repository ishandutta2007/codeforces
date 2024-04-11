#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <sstream>
#include <queue>

using namespace std;

const long double EPS = 1e-7;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n, p, sum_b = 0, sum_a = 0;
	cin >> n >> p;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum_a += a[i];
		sum_b += b[i];
	}

	if (sum_a <= p) {
		cout << -1 << endl;
	}
	else {
		long double l = 0, r = 100000000000.0;
		for (int j = 0; j < 150; j++) {
			long double m = (l + r) / 2;
			long double res_t = 0;
			for (int i = 0; i < n; i++) {
				res_t += (a[i] * m - b[i]) < 0 ? 0 : (a[i] * m - b[i]) / p;
			}
			if (res_t > m + EPS)
				r = m;
			else
				l = m;
		}
		cout << fixed << setprecision(9) << l << endl;
	}

	return 0;
}