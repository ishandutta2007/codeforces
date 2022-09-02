#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// If permutation is identity, n
	// otherwise, mix up the permutations!
	// f g c e a d b
	// | | / | | | /
	// | \-+-+-+-+-\
	// | /-+-+-/ | |
	// | | | \-\ | |
	// | | | /-+-/ |
	// \-+-+-+-+-\ |
	//   | | | | | |
	//   a b d e f g
	//   | | | | | |
	// /-/-/-+-+-+-+
	// | | | | | | |
	// a b c d e f g
	// 1 2 3 1 1 1 2
	
	int n;
	cin >> n;
	vector<int> tars(n);
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		tars[t-1] = i;
	}

	// Identity permutation is a special case
	bool ident = true;
	for (int i = 0; i < n; ++i) {
		if (tars[i] != i) ident = false;
	}
	if (ident) {
		cout << n << '\n';
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) cout << ".";
			cout << '\n';
		}
	} else {
		cout << n-1 << '\n';
		
		// Mangle the permutation
		vector<bool> used(n, false);
		int pv = 0;
		int tt = -1;
		for (int i = 0; i < n; ++i) {
			if (! used[i]) {
				// Mark as used
				int j = i;
				while(true) {
					used[j] = true;
					j = tars[j];
					if (j == i) break;
				}

				// Update tars, output
				cout << "\\";
				swap(tt, tars[i]);
				pv = i;
			} else {
				cout << ".";
			}
		}
		pv = 0;
		cout << '\n';

		// Fix the columns
		for (int y = 1; y < n; ++y) {
			
			int npv = -1;
			for (int x = 0; x < n; ++x) {
				if (tars[x] == pv) npv = x;
			}

			for (int x = 0; x < n; ++x) {
				if (x == pv || x == npv) {
					if (npv < pv) cout << "\\";
					else cout << "/";
				} else {
					cout << ".";
				}
			}
			cout << '\n';

			swap(tars[pv], tars[npv]);
			pv = npv;
		}
	}
}