#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// a * b > INF <=> a > INF / b
// INF / b < floor(INF / b) + 1
// floor(INF / b) + 1 > a implies a * b > INF
const ll INF = 1e18;
const ll INF_ROOT = 1e9;

ll safeMult(ll a, ll b) {
	if (a <= INF_ROOT && b <= INF_ROOT) return a * b;
	if (b == 0) return 0;

	if (a > INF / b + 1) return INF + 1;
	ll res = a * b;
	if (res > INF) return INF + 1;
	return res;
}

ll safePow(ll a, int b) {
	ll tmp = a;
	ll res = 1;
	for (int j = 0; (res <= INF) && ((1<<j) <= b); ++j) {
		if (b & (1<<j)) res = safeMult(res, tmp);
		tmp = safeMult(tmp, tmp);
	}
	return res;
}

const int N = 100;
int divs[N];
int mob[N];
vector<int> primes;

void sieve() {
	for (int i = 0; i < N; ++i) divs[i] = -1;
	for (int i = 2; i < N; ++i) {
		if (divs[i] == -1) {
			divs[i] = primes.size();
			primes.push_back(i);
			mob[i] = -1;
		}
		for (int j = 0; j <= divs[i]; ++j) {
			int t = i * primes[j];
			if (t >= N) break;
			
			divs[t] = j;
			if (j == divs[i]) mob[t] = 0;
			else mob[t] = -1 * mob[i];
		}
	}
}

int main() {
	// elegant = not power of 2, 3, 4, ...
	// use inclusion-exclusion! Multiplier is the mobius-function
	// since 2^64 > 10^5, we only need to consider first 64
	
	// res = (n-1) + (mob[2]cou[2] + mob[3]cou[3] + mob[4]cou[4] + ... + mob[64]cou[64])

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	sieve();

	int t;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		ll n;
		cin >> n;

		ll res = n-1;
		ll high = INF_ROOT;
		for (int i = 2; i <= 64; ++i) {
			ll low = 1;
			while(low != high) {
				ll mid = (low + high + 1) >> 1;
				ll sub = safePow(mid, i);
				if (sub <= n) low = mid;
				else high = mid-1;
			}
			if (low == 1) break;

			res += mob[i] * (high - 1);
		}
		cout << res << '\n';
	}
}