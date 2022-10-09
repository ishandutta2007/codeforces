
#include <iostream>
#include <climits>

using namespace std;

int n, t, s, d, x, M, r;

int main() {
	cin >> n >> t;
	M = INT_MAX;
	r = 0;
	for(int i = 0; i < n; i++) {
		cin >> s >> d;
		if(s >= t) x = s - t;
		else {
			x = d - ((t - s) % d);
			if(x == d) x = 0;
		}
		if(x < M) {
			M = x;
			r = i + 1;
		}
	}
	cout << r << endl;
}