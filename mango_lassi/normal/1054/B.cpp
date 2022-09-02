#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int res = -1;
	int mex = 0; // We have all integers < this
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a > mex) {
			res = i+1;
			break;
		} else if (a == mex) {
			++mex;
		}
	}
	cout << res << '\n';
}