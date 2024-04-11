#include <iostream>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int query(ll ax, ll bx, bool swp) {
	if (swp) {
		cout << "? " << bx << ' ' << ax << endl;
		int ans;
		cin >> ans;
		return -ans;
	} else {
		cout << "? " << ax << ' ' << bx << endl;
		int ans;
		cin >> ans;
		return ans;
	}
}

bool geq(ll ax, ll bx, bool swp) {
	return query(ax, bx, swp) >= 0;
}

int main() {
	ll ax = 0;
	ll bx = 0;

	// Possibilities are: 1 1, 1 0, 0 1, 0 0 (a has bit, b has bit)
	// Say that we know beforehand that a >= b
	// -> 1 1, 1 0, 0 0

	// Ask a^bit >= b
	// YES: 1 0 '>=, 0 0 '>=
	// 	Ask a^bit >= b^bit
	// 	YES: 0 0 '>=
	//	NO: 1 0 '>=
	// NO: 1 1 '>=, 1 0 '<
	// 	Ask a >= b^bit
	//	YES: 1 1 '>=
	// 	NO: 1 0 '<
	// Special handling for last bit to reclaim initial a >= b check

	bool swp = !geq(0, 0, false); // Whether A and B have been swapped
	for (int i = 29; i > 0; --i) {
		ll bit = (((ll)1)<<i);
		if (geq(ax ^ bit, bx, swp)) {
			if (geq(ax ^ bit, bx ^ bit, swp)) {
				// Neither has bit, a' >= b'
				ax = ax;
				bx = bx;
			} else {
				// A has bit, a' >= b'
				ax = ax ^ bit;
				bx = bx;
			}
		} else {
			if (geq(ax, bx ^ bit, swp)) {
				// Both have bit, a' >= b'
				ax = ax ^ bit;
				bx = bx ^ bit;
			} else {
				// A has bit, a' < b'
				ax = ax^bit;
				bx = bx;

				swap(ax, bx);
				swp = !swp;
			}
		}
	}

	// Special case handling for last bit
	// 1 1, 1 0, 0 0 -> 1 0, 1 1, 0 1 (>, =, <)
	int lst = query(ax, bx ^ 1, swp);
	if (lst == 1) {
		ax = ax ^ 1;
		bx = bx ^ 1;
	} else if (lst == 0) {
		ax = ax ^ 1;
		bx = bx;
	} else {
		ax = ax;
		bx = bx;
	}

	// Print answer
	if (swp) {
		cout << "! " << bx << ' ' << ax << endl;
	} else {
		cout << "! " << ax << ' ' << bx << endl;
	}
}