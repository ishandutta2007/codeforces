#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

/*
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
*/

const int K = 25;
int ans[K] = {1,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;

		bool toggle = false;
		int res = v;
		int k = 0;
		for (int j = 1; j < res; j <<= 1) {
			if ((res & j) == 0) {
				toggle = true;
				res |= j;
			}
			++k;
		}
		if (toggle) {
			cout << res << '\n';
		} else {
			cout << ans[k-1] << '\n';
		}
	}
}