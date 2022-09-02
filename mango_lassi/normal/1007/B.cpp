#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1 + (int)1e5;

int div_ind[N];
int cou_div[N];
int pri_pow[N];
vector<int> primes;

void sieve() {
	for (int i = 0; i < N; ++i) div_ind[i] = -1;
	cou_div[1] = 1;

	for (int i = 2; i < N; ++i) {
		if (div_ind[i] == -1) {
			div_ind[i] = primes.size();
			pri_pow[i] = 1;
			cou_div[i] = 2;
			primes.push_back(i);
		}
		for (int j = 0; j <= div_ind[i]; ++j) {
			int t = i * primes[j];
			if (t >= N) break;

			div_ind[t] = j;
			if (j == div_ind[i]) {
				pri_pow[t] = pri_pow[i] + 1;
				cou_div[t] = cou_div[i] + cou_div[i] / pri_pow[t];
			} else {
				pri_pow[t] = 1;
				cou_div[t] = cou_div[i] << 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	sieve();

	int t;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		int a, b, c;
		cin >> a >> b >> c;

		// number of ones that are ONLY in the given mask
		ll only[8];
		only[7] = cou_div[__gcd(__gcd(a, b), c)];
		only[6] = cou_div[__gcd(b, c)] - only[7];
		only[5] = cou_div[__gcd(a, c)] - only[7];
		only[4] = cou_div[c] - only[5] - only[6] - only[7];
		only[3] = cou_div[__gcd(a, b)] - only[7];
		only[2] = cou_div[b] - only[3] - only[6] - only[7];
		only[1] = cou_div[a] - only[3] - only[5] - only[7];
		only[0] = 0;

		ll res = 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = i; j < 8; ++j) {
				for (int k = j; k < 8; ++k) {
					bool can = false;
					can |= (i & 1) && (j & 2) && (k & 4);
					can |= (i & 2) && (j & 1) && (k & 4);
					can |= (i & 1) && (j & 4) && (k & 2);
					can |= (i & 4) && (j & 1) && (k & 2);
					can |= (i & 2) && (j & 4) && (k & 1);
					can |= (i & 4) && (j & 2) && (k & 1);
					if (! can) continue;
					
					// Handle equalities
					ll add = 0;
					if (i == j) {
						if (j == k) {
							add = only[i] * (only[i] - 1) * (only[i] - 2) / 6 + only[i] * (only[i] - 1) + only[i];
						} else {
							add = only[i] * (only[j] + 1) / 2 * only[k];
						}
					} else if (j == k) {
						add = only[i] * only[j] * (only[k] + 1) / 2;
					} else {
						add = only[i] * only[j] * only[k];
					}
					res += add;
				}
			}
		}
		cout << res << '\n';
	}
}