#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int res = 1; // 0-0
	int pa = 0;
	int pb = 0;

	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		
		int overlap = min(a, b) - max(pa, pb) + 1;
		if (pa == pb) --overlap;
		res += max(0, overlap);
		pa = a;
		pb = b;
	}
	cout << res << '\n';
}