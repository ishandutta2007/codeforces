#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function for precalculating primes and prime divisors
pair<vector<int>, vector<int>> sieve(int n) {
	vector<int> div_ind(n+1, -1), primes;
	for (int i = 2; i <= n; ++i) {
		if (div_ind[i] == -1) {
			div_ind[i] = primes.size();
			primes.push_back(i);
		}
		for (int j = 0; j <= div_ind[i]; ++j) {
			int t = primes[j] * i;
			if (t > n) break;
			div_ind[t] = j;
		}
	}
	return {primes, div_ind};
}

vector<int> primeDivs(int v, const vector<int>& primes, const vector<int>& div_ind) {
	vector<int> res;
	while(v > 1) {
		int j = div_ind[v];
		res.emplace_back(j);
		while(v % primes[j] == 0) v /= primes[j];
	}
	return res;
}

const int V = 1e5;
const int N = 1e5;
const int H = 20;
int nxt[N+1][H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> primes, div_ind;
	tie(primes, div_ind) = sieve(V);

	int n, q;
	cin >> n >> q;

	vector<int> vals(n);
	for (int& v : vals) cin >> v;
	
	int k = primes.size();
	vector<int> prev(k, n);
	
	nxt[n][0] = n;
	for (int i = n-1; i >= 0; --i) {
		nxt[i][0] = n;
		vector<int> ps = primeDivs(vals[i], primes, div_ind);
		for (int p : ps) {
			nxt[i][0] = min(nxt[i][0], prev[p]);
			prev[p] = i;
		}
		if (i+1 < n) nxt[i][0] = min(nxt[i][0], nxt[i+1][0]);
	}
	for (int j = 1; j < H; ++j) {
		nxt[n][j] = n;
		for (int i = 0; i < n; ++i) nxt[i][j] = nxt[nxt[i][j-1]][j-1];
	}

	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		
		int res = 1;
		for (int j = H-1; j >= 0; --j) {
			if (nxt[a][j] <= b) {
				res += (1 << j);
				a = nxt[a][j];
			}
		}
		cout << res << '\n';
	}
}