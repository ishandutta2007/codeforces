#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
int a[100005];
set <long long> present;
int ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		if (present.find((long long) a[i] * k) == present.end()) {
			ans++;
			present.insert(a[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}