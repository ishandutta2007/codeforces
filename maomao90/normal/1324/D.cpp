#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[200005], b[200005], diff[200005];
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) diff[i] = a[i] - b[i];
	sort(diff, diff + n);
	for (int i = 0; i < n; i++) {
        if (diff[i] <= 0) {
            int dist = n - (upper_bound(diff, diff + n, -diff[i]) - diff);
            ans += dist;
        }
        else {
			ans += n - i - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}