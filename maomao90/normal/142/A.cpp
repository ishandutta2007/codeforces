#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000000005

int n;
bool isPrime[100005];
vector <int> primes;
vector <int> factors;
long long minans = INF, maxans = 0;

int main() {
	scanf("%d", &n);
	for (long long A = 1; A * A * A <= n + 5; A++) {
		for (long long B = A; A * B * B <= n + 5; B++) {
            if (n % (A * B) != 0) continue;
			int C = n / A / B;
			long long cur1 = ((long long) (A + 1) * (B + 2) * (C + 2)) - n,
                            cur2 = ((long long) (A + 2) * (B + 1) * (C + 2)) - n,
                            cur3 = ((long long) (A + 2) * (B + 2) * (C + 1)) - n;
			minans = min(minans, min(cur1, min(cur2, cur3)));
			maxans = max(maxans, max(cur1, max(cur2, cur3)));
		}
	}
	printf("%lld %lld\n", minans, maxans);
	return 0;
}