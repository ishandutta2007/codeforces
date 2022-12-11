#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 2001000;

int prime[MAXN];
int palin[MAXN];

int digits[20]; int h;

void solve() {
	prime[0] = prime[1] = 1;
	for (int i = 2; i * i < MAXN; i++) {
		if (prime[i] ) {
			continue;
		}

		for (int j = i * i; j < MAXN; j += i) {
			prime[j] = 1;
		}
	}

	int sum = 0;
	for (int i = 0; i < MAXN; i++) {
		sum += 1 - prime[i];
		prime[i] = sum;
	}

	for (int i = 1; i < MAXN; i++) {
		h = 0;
		int ii = i;
		while (ii) {
			digits[++h] = ii % 10;
			ii /= 10;
		}

		palin[i] = 1;
		for (int j = 1; j <= h / 2; j++) {
			if (digits[j] != digits[h - j + 1] ) {
				palin[i] = 0;
				break;
			}
		}

		palin[i] += palin[i - 1];
	}

	int p, q; cin >> p >> q;

	int answer = -1;
	for (int n = 1; n < MAXN; n++) {
		if (q * 1ll * prime[n] <= p * 1ll * palin[n] ) {
			answer = n;
		}
	}

	if (answer == MAXN - 1) {
		cout << "Palindromic tree is better than splay tree\n";
		return;
	}
	cout << answer << "\n";
}

int main() {
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}