#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

const int M = 300000;
const int MAGIC = 7;
vector<int> divisor[M + 10];
int cnt[M + 10][MAGIC + 5], scnt[M + 10][MAGIC + 5];
int n, x, vis[M + 10], mu[M + 10], dp[M + 10];

void add(int x, int v, int val) {
	for (auto d : divisor[x]) scnt[d][v] += val;
}
void update(int x, int v, bool init = 0) {
	if (!init) {
		if (dp[x] <= v) return;
		add(x, dp[x], -1);
		dp[x] = v;
		add(x, v, 1);
	} else {
		dp[x] = v;
		add(x, v, 1);
	}
}

int main() {
	for (int i = 1; i <= M; i++)
		for (int j = i; j <= M; j += i) {
			divisor[j].push_back(i);
		}
	for (int i = 1; i <= M; i++) {
		if (i == 1) mu[i] = 1;
		for (auto d : divisor[i]) if (d != i) {
				mu[i] -= mu[d];
			}
	}
	scanf("%d", &n);
	int d = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		vis[x] = 1;
		d = gcd(d, x);
	}
	if (d != 1) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= M; i++) {
		update(i, MAGIC, 1);
	}
	for (int i = 1; i <= M; i++) if (vis[i]) {
			// dp[x] = gcd = x element
			update(i, 1);
			for (auto d : divisor[i])
				for (int j = 1; j <= MAGIC; j++) cnt[d][j] = 0;
			for (auto d2 : divisor[i]) if (mu[d2]) {
					for (auto d : divisor[i / d2]) {
						for (int j = 1; j <= MAGIC; j++)
							cnt[d][j] += mu[d2] * scnt[d * d2][j];
					}
				}
			for (auto d : divisor[i]) {
				for (int j = 1; j <= MAGIC; j++) if (cnt[d][j] > 0) {
						update(d, j + 1);
						break;
					}
			}
		}
	printf("%d\n", dp[1]);
}