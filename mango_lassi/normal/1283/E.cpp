#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
int used[N+2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++used[x];
	}

	int p0 = -1; // previous low
	int p1 = -1; // previous high
	int low = 0;
	int high = 0;
	for (int i = 1; i <= n; ++i) {
		if (used[i] && p0 < i-1) {
			++low;
			p0 = i+1;
		}
		if (used[i] && p1 < i-1) {
			++high;
			p1 = i-1;
			--used[i];
		}
		if (used[i] && p1 < i) {
			++high;
			p1 = i;
			--used[i];
		}
		if (used[i] && p1 < i+1) {
			++high;
			p1 = i+1;
			--used[i];
		}
	}
	cout << low << ' ' << high << '\n';
}