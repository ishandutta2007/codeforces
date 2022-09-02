#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int K = 100;
int cou[K];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cou[v % k];
	}

	int res = 0;
	for (int j = 1; j < (k-j); ++j) {
		int i = k-j;
		res += min(cou[j], cou[i]);
	}
	res += cou[0] / 2;
	if (k % 2 == 0) res += cou[k / 2] / 2;
	cout << 2 * res << '\n';
}