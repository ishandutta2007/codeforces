#include <bits/stdc++.h>
using namespace std;
signed main() {
	#define int long long
	int h, l;
	cin >> h >> l;
	double k = l * l - h * h;
	k = k / (2 * h);
	cout << fixed << setprecision(6) << k;
    return 0;
}