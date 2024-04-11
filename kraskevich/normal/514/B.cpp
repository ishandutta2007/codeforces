#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    long long x0, y0;
    cin >> x0 >> y0;
    for (int i = 0; i < n; i++) {
	cin >> x[i] >> y[i];
	x[i] -= x0;
	y[i] -= y0;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
	bool old = false;
	for (int j = 0; j < i; j++)
	    if (x[i] * y[j] - x[j] * y[i] == 0)
		old = true;
	if (!old)
	    res++;
    }
    cout << res << endl;
    return 0;
}