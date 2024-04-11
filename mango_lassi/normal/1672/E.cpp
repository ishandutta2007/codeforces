#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int w) {
	cout << "? " << w << endl;
	int res;
	cin >> res;
	return res;
}
void answer(int v) {
	cout << "! " << v << endl;
}

int main() {
	int n;
	cin >> n;
	
	// minw(h): minimum width to get height at most h
	// If the optimal height is h:
	// minw(1) - (h-1) <= ANS <= minw(1)
	
	int low = n;
	int high = n * 2000 + (n-1);
	while(low != high) {
		int mid = (low + high) >> 1;
		if (ask(mid) == 1) high = mid;
		else low = mid + 1;
	}

	int res = low;
	for (int h = 2; h <= n; ++h) {
		int guess = low / h;
		
		int offer = ask(guess);
		if (offer != 0 && offer <= h) {
			res = min(res, h * guess);
		}
	}
	answer(res);
}