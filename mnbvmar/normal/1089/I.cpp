#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 420;

int mod;

int fact[kMaxN];      // fact[k] = k!
int nopref[kMaxN];    // nopref[k] = num permutations that can't be split into prefix and suffix
int dp_fact[kMaxN][kMaxN];   // dp_fact[k, n] = \sum_{s1+...+sk=n} \prod_{i=1}^k (si)!
int dp_nopref[kMaxN][kMaxN]; // dp_nopref[k, n] = \sum_{s1+...+sk=n} \prod_{i=1}^k nopref[si]

int ngood[kMaxN];     // ngood[k] = number of interval-free permutations of size k
int nbad[kMaxN];      // nbad[k] = k! - ngood[k]

void MakeFactorials() {
	fact[0] = 1;
	for (int i = 1; i < kMaxN; ++i) {
		fact[i] = (long long)fact[i - 1] * i % mod;
	}
}

// n! - nopref[n] = \sum_{k=1}^{n-1} nopref[k] * (n-k)!
void MakeNoPref() {
	for (int n = 1; n < kMaxN; ++n) {
		nopref[n] = fact[n];
		for (int k = 1; k < n; ++k) {
			nopref[n] = (nopref[n] - (long long)nopref[k] * fact[n - k]) % mod;
			if (nopref[n] < 0) { nopref[n] += mod; }
		}
	}
}

// dest[k, n] = \sum_{s1+...+sk=n} \prod_{i=1}^k src[si]
void MakeProdSum(int src[kMaxN], int dest[kMaxN][kMaxN]) {
	dest[0][0] = 1;
	for (int cnt = 1; cnt < kMaxN; ++cnt) {
		for (int n = cnt; n < kMaxN; ++n) {
			for (int i = 1; i <= n; ++i) {
				dest[cnt][n] = (dest[cnt][n] + (long long)dest[cnt - 1][n - i] * src[i]) % mod;
			}
		}
	}
}

void CountGoodPerms() {
	// Smallest results computed by hand.
	ngood[1] = 1;
	ngood[2] = 2;
	nbad[3] = 6;
	for (int n = 4; n < kMaxN; ++n) {
		// nbad[n] = \sum_{k=4}^{n-1} ngood[k]*dp_fact[k][n] + \sum_{k=2}^n 2*dp_nopref[k][n]
		for (int k = 4; k < n; ++k) {
			nbad[n] = (nbad[n] + (long long)ngood[k] * dp_fact[k][n]) % mod;
		}
		for (int k = 2; k <= n; ++k) {
			nbad[n] = (nbad[n] + 2LL * dp_nopref[k][n]) % mod;
		}
		ngood[n] = (mod + fact[n] - nbad[n]) % mod;
	}
}

void Preproc() {
	MakeFactorials();
	MakeNoPref();
	MakeProdSum(fact, dp_fact);
	MakeProdSum(nopref, dp_nopref);
	CountGoodPerms();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t >> mod;

	Preproc();
	while (t--) {
		int n;
		cin >> n;
		cout << ngood[n] << "\n";
	}
}