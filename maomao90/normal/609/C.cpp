#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int m[100005];
int sum;
int lo, nLo;
int ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
		sum += m[i];
	}
	if (sum == 0) {
        printf("0\n");
        return 0;
	}
	lo = sum / n;
	if (lo != 0) nLo = n - (sum % n);
	else nLo = n - sum;
	sort(m, m + n);
	for (int i = 0; i < n; i++) ans += max(0, i < nLo ? lo - m[i] : lo + 1 - m[i]);
	printf("%d\n", ans);
	return 0;
}