#include <iostream>
#include <cstdlib>
using namespace std;
const int size = 1000005;

bool unprime[size];
int main() {
	int n;
	cin >> n;
	bool found = false;
	for (long long i = 2; i < size; i++)
		if (!unprime[i])
			for (long long j = i * i; j < size; j += i) {
				if (j == 1000000)
					j = size - 5;
				unprime[j] = true;
				if ((!found) && (j < n))
					if (unprime[j] && unprime[n - j]) {
						found = true;
						cout << j << ' ' << n - j;
					}
			}

	return 0;
}