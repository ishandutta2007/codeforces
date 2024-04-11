#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int lim = 1400000;

int prime[lim];
int pal[lim];
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int revar[9];
	int i, j, k, p, q;
	cin >> p >> q;
	for (i = 0; i < lim; ++i)
		prime[i] = 1;
	prime[1] = 0;
	for (i = 2; i < lim; ++i)
		if (i < 10000)
			for (j = i * i; j < lim; j += i)
				prime[j] = 0;

	for (i = 1; i < lim; ++i) {
		j = i;
		k = 0;
		while (j) {
			revar[k] = j % 10;
			++k;
			j /= 10;
		}
		pal[i] = 1;
		for (j = 0; j < k; ++j)
			if (revar[j] != revar[k - j - 1])
				pal[i] = 0;
	}

	pal[0] = 0;
	prime[0] = 0;

	int res = 1;
	for (i = 1; i < lim; ++i) {
		pal[i] += pal[i - 1];
		prime[i] += prime[i - 1];
		if (prime[i] * q <= pal[i] * p)
			res = i;
	}
	cout << res;
	return 0;
}