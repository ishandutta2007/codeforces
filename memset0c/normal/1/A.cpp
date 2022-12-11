#include <bits/stdc++.h>
using namespace std;
long long a, n, m;
int main() {
	cin >> n >> m >> a;
	cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;
	return 0;
}