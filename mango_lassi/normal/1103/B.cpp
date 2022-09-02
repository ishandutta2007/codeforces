#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll V = 1e9;

bool ask(ll x, ll y) {
	cout << "? " << x << ' ' << y << endl;
	char v;
	cin >> v;
	return v == 'x';
}

void answer(ll a) {
	cout << "! " << a << endl;
}

void play() {
	ll low = 1;
	ll high = -1;
	while(true) {
		if (ask(low, 2*low)) {
			high = 2*low;
			break;
		} else {
			low = 2*low;
		}
	}
	high = min(high, V);

	// low <= mod <= high
	if (low == 1) {
		if (ask(2, 1)) {
			answer(1);
		} else {
			answer(2);
		}
	} else {
		// low < mod <= high
		while(high - low > 1) {
			ll mid = (low + high) >> 1;
			if (ask(low, mid)) {
				// low (mod a) >= mid (mod a)
				// -> mid >= mod
				high = mid;
			} else {
				// low (mod a) < mid (mod a)
				// -> mid < mod
				low = mid;
			}
		}
		answer(high);
	}
}

// 1. 2H >= mod > H
// 2. H % mod 
// Ask H H+H/2. 

// 1. Set low = 1
// 2. ask low, 2*low

int main() {
	while(true) {
		string str;
		cin >> str;
		if (str == "start") {
			play();
		} else {
			return 0;
		}
	}
}