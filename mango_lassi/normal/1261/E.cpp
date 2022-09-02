#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;

const int N = 1 + (int)1e3;
bitset<N> res[N];
bitset<N> act;
int as[N];

void recSolve(int n, int& oi) {
	/*
	cerr << "recSolve ";
	for (int j = 0; j < n; ++j) cerr << act[j]; cerr << " ";
	for (int j = 0; j < n; ++j) cerr << as[j] << ' ';
	cerr << endl;
	*/

	int mn = -1;
	int cou = 0;
	for (int i = 0; i < n; ++i) {
		if (act[i]) {
			++cou;
			if (mn == -1 || as[i] < as[mn]) mn = i;
		}
	}
	if (cou == 0) return;
	if (cou == as[mn]) {
		/*
		if (cou == 1) {
			res[oi][mn] = 1;
			--as[mn];
			++oi;
		} else {
		*/
		for (int j = 0; j <= cou; ++j) {
			int ind = 0;
			for (int i = 0; i < n; ++i) {
				if (act[i]) {
					++ind;
					if (ind == j) continue;

					res[oi][i] = 1;
					--as[i];
				}
			}
			++oi;
		}
	} else {
		act[mn] = 0;
		for (int i = 0; i < n; ++i) {
			if ((act[i] && as[i] > 1) || i == mn) {
				--as[i];
				res[oi][i] = 1;
			}
		}
		int x = oi;
		++oi;

		recSolve(n, oi);

		// Add mn to some operations. Since all operations after this are unique,
		// All operations before this contain the previous minimums, and there
		// are at least as[mn] + 1 operations after this, we can find as[mn]
		// operations to add this to.
		for (int j = x+1; j < oi && as[mn] > 0; ++j) {
			res[j][mn] = 1;
			if (res[j] == res[x]) {
				// Undo
				res[j][mn] = 0;
			} else {
				--as[mn];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// If all numbers equal n, solve trivially.
	// Find minimum element. Subtract one from all

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		act[i] = 1;
	}

	int cou = 0;
	recSolve(n, cou);
	cout << cou << '\n';
	for (int i = 0; i < cou; ++i) {
		for (int j = 0; j < n; ++j) cout << res[i][j]; cout << '\n';
	}
}