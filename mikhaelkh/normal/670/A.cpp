#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int calc(int n) {
	int k = n / 7, m = n % 7;
	return 2*k + max(0, m-5);
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "0 1\n";
		return 0;
	}
	cout << calc(n) << ' ' << 2+calc(n-2) << endl;
	return 0;
}