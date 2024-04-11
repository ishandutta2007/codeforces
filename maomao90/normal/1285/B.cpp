#include <cstdio>

using namespace std;

int t;
int n;
long long sum, maxSum;
bool takeAll;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum = 0; maxSum = 0;
		long long cur = 0;
		takeAll = true;
		int lastChange = 0;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			sum += a;
			cur += a;
            if (cur <= 0) {
                cur = 0;
                takeAll = false;
            }
            if (cur > maxSum) {
                maxSum = cur;
                lastChange = i;
            }
		}
		if (lastChange != n - 1) takeAll = false;
		printf(sum > maxSum || takeAll ? "YES\n" : "NO\n");
	}
	return 0;
}