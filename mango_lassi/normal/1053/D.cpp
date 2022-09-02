#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

const int N = 2 * (int)1e5;
const int M = 3 * (int)1e6;
int divs[M];
vector<int> primes;

vector<pair<int, int>> locks;
vector<int> maxes[3];

int vals[N];
int free_init = 0;

pair<int, int> brute(int a, int b, int x, int p) {
	vector<int> apps(p, -1);
	apps[x] = 0;
	for (int i = 1;; ++i) {
		x = (a*x + b) % p;
		if (apps[x] != -1) {
			return {i - apps[x], apps[x]};
		} else {
			apps[x] = i;
		}
	}
}

vector<pair<int, int>> getDivs(int v) {
	vector<pair<int, int>> res;
	while(v > 1) {
		int j = divs[v];
		int k = 0;
		while(divs[v] == j) {
			v /= primes[j];
			++k;
		}
		res.push_back({j, k});
	}
	return res;
}

ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return (a * modPow(a, b-1)) % MOD;
	return modPow(a*a % MOD, b / 2);
}

int main() {
	for (int i = 0; i < M; ++i) divs[i] = -1;
	for (int i = 2; i < M; ++i) {
		if (divs[i] == -1) {
			divs[i] = primes.size();
			primes.push_back(i);
		}
		for (int j = 0; j <= divs[i]; ++j) {
			int t = primes[j] * i;
			if (t >= M) break;
			divs[t] = j;
		}
	}
	maxes[0].resize(primes.size(), 0);
	maxes[1].resize(primes.size(), 0);
	maxes[2].resize(primes.size(), 0);
	locks.resize(primes.size(), {0, 0});

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> vals[i];

	// With p^k, we have (cycle length, initial)
	// 1. (p^k, 0)			(a = 1, b = 1, x = 0)
	// 2. (p-1, 0)			(a = g, b = 0, x = 1), g is a generator
	// 3. (1, k)	 		(a = p, b = 0, x = 1)
	// Answer is LCA(cycle lengths) + max(initial)
	
	for (int i = 0; i < n; ++i) {
		vector<pair<int, int>> divs = getDivs(vals[i]);
		for (auto pr : divs) {
			int j = pr.first;
			int k = pr.second;
			if (maxes[0][j] < k) swap(maxes[0][j], k);
			if (maxes[1][j] < k) swap(maxes[1][j], k);
			if (maxes[2][j] < k) swap(maxes[2][j], k);
		}
	}

	for (int j = (int)primes.size() - 1; j >= 0; --j) {
		if (maxes[0][j] > 0 && (locks[j].first >= maxes[0][j] || maxes[1][j] > 0)) {
			int p = primes[j];
			vector<pair<int, int>> divs = getDivs(p-1);
			for (auto pr : divs) {
				int j = pr.first;
				int k = pr.second;
				if (k > locks[j].first) {
					locks[j] = {k, 1};
				} else if (k == locks[j].first) {
					++locks[j].second;
				}
			}
		}
	}
	
	// Calculate the LCA
	ll res = 1;
	for (int j = 0; j < primes.size(); ++j) {
		res = (res * modPow(primes[j], max(maxes[0][j], locks[j].first))) % MOD;
	}
	
	// Calculate the initial
	int ini = 0;
	for (int j = 0; j < primes.size(); ++j) {
		int b = 0;
		if (maxes[0][j] == 0) continue;
		if (locks[j].first < maxes[0][j]) ++b;
		
		bool can = true;
		if (maxes[b+1][j] == 0) {
			// Is turning p -> p-1 pointless?
			vector<pair<int, int>> divs = getDivs(primes[j]-1);
			for (auto pr : divs) {
				int jj = pr.first;
				int k = pr.second;
				if (locks[jj].first == k && locks[jj].second == 1) can = false;
			}
		}
		if (can) {
			ini = max(ini, maxes[b][j]);
		}
	}
	
	cout << (res + ini) % MOD << '\n';
}