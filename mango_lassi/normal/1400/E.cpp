#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int recSolve(int a, int b, int cut, const vector<int>& vec) {
	if (b < a) return 0;
	else if (a == b) return vec[a] == cut ? 0 : 1;

	// Interval minimum
	int x = a;
	for (int i = a+1; i <= b; ++i) {
		if (vec[i] < vec[x]) x = i;
	}

	// Solve left and right side
	int le = recSolve(a, x-1, vec[x], vec);
	int ri = recSolve(x+1, b, vec[x], vec);
	
	// Combine
	return min(b-a+1, vec[x] - cut + le + ri);
}

void solve() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	// Trivial in n ops
	// Solve for intervals, with value if we delete horizontally up to the minimum in the interval,
	// and value if we dont.

	cout << recSolve(0, n-1, 0, vals) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}