#include <bits/stdc++.h>

using namespace std;
 
double calc(const vector<int>& l, const vector<int>& r, int low, int eq, int high, int val, int pos) {
    if (pos == l.size()) {
	if (high == 1 && eq >= 1 || high == 0 && eq >= 2)
	    return val;
	return 0;
    }
    double res = 0;
    res += calc(l, r, low + 1, eq, high, val, pos + 1) * min(1.0, max(0, val - l[pos]) * 1.0 / (r[pos] - l[pos] + 1));
    if (val >= l[pos] && val <= r[pos])
	res += calc(l, r, low, eq + 1, high, val, pos + 1) * 1.0 / (r[pos] - l[pos] + 1);
    res += calc(l, r, low, eq, high + 1, val, pos + 1) * min(1.0, max(0, r[pos] - val) * 1.0 / (r[pos] - l[pos] + 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++)
	cin >> l[i] >> r[i];
    double res = 0;
    for (int i = 1; i <= 10 * 1000; i++) {
	//if (calc(l, r, 0, 0, 0, i, 0) > 1e-9)
	  //  cout << i << " " << calc(l, r, 0, 0, 0, i, 0) / i << endl;
	res += calc(l, r, 0, 0, 0, i, 0);
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res << endl;
    return 0;
}