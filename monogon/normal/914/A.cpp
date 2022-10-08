#include <iostream>
#include <cmath>

using namespace std;

int n, a, best = -1e6;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		int root = sqrt(a);
		if(root * root != a && a > best) {
			best = a;
		}
	}
	cout << best << endl;
}