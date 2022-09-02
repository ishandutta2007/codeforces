#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// Find for every integer 1 ... N how many integers are coprime with it.
// CP[i]	= sum_{j = 1 to N} g(j) [gcd(i, j) = 1]
// 		= sum_{j = 1 to N} g(j) sum_{d | i, j} f(d)
// 		= sum_{d | i} f(d) sum_{j = d to N, +=d} g(j)
// 		= sum_{d | i) f(d) DP[d]

const int INF = 1e9 + 7;
const int N = 3 * (int)1e5;

bool match[N+1];
int dp[N+1];
int cop[N+1];

int divs[N+1];
int mob[N+1];
vector<int> primes;

void sieve() {
	mob[1] = 1;
	for (int i = 0; i <= N; ++i) divs[i] = -1;

	for (int i = 2; i <= N; ++i) {
		if (divs[i] == -1) {
			divs[i] = primes.size();
			mob[i] = -1;

			primes.push_back(i);
		}
		for (int j = 0; j <= divs[i]; ++j) {
			int t = i * primes[j];
			if (t > N) break;

			divs[t] = j;
			if (j != divs[i]) mob[t] = -mob[i];
			else mob[t] = 0;
		}
	}
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int dist[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	sieve();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		match[v] = true;
	}
	
	for (int d = 1; d <= N; ++d) {
		dp[d] = 0;
		for (int j = d; j <= N; j += d) dp[d] += match[j];
		dp[d] *= mob[d];
	}
	for (int d = 1; d <= N; ++d) cop[d] = 0;
	for (int d = 1; d <= N; ++d) {
		for (int j = d; j <= N; j += d) cop[j] += dp[d];
	}

	if (match[1]) {
		cout << "1\n";
	} else {
		// cop[d] is now the number of numbers that are coprime with d
		int ans = INF;
		for (int d = 1; d <= N; ++d) {
			if (match[d]) {
				// Check this one's masks
				vector<int> prime_divs;
				int tmp = d;
				while(tmp > 1) {
					int p = primes[divs[tmp]];
					prime_divs.push_back(p);
					while(tmp % p == 0) tmp /= p;
				}

				vector<int> parts;
				int c = prime_divs.size();
				for (int i = 0; i < (1<<c); ++i) {
					int v = 1;
					for (int j = 0; j < c; ++j) {
						if (i & (1<<j)) v *= prime_divs[j];
					}
					parts.push_back(v);
				}

				vector<int> que;
				for (auto v : parts) {
					if (cop[v]) {
						dist[v] = 1;
						que.push_back(v);
					} else {
						dist[v] = INF;
					}
				}

				for (int i = 0; i < que.size(); ++i) {
					for (int j = 0; (j < i) && (dist[que[j]] == 1); ++j) {
						int t = (ll)que[i] * que[j] / gcd(que[i], que[j]);

						if (dist[t] > dist[que[i]] + 1) {
							dist[t] = dist[que[i]] + 1;
							que.push_back(t);
						}
					}
				}
				if (dist[parts.back()] < INF) ans = min(ans, dist[parts.back()] + 1);
			}
		}
		if (ans == INF) ans = -1;
		cout << ans << '\n';
	}
}