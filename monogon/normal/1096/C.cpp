#include <iostream>
#include <algorithm>

#define M 998244353

using namespace std;

int T;
int n;

int main() {

	cin >> T;
	for(int k = 0; k < T; k++) {
		cin >> n;
		for(long long i = 3; i <= 360; i++) {
			if((i * (i - 2) * n) % (180 * i - 360) == 0 && n * i * (i - 2) / (180 * i - 360) <= i - 2) {
				cout << i << endl;
				break;
			}
		}
	}
}