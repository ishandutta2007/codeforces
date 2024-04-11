#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1] * 2 && a[i] != a[i - 1]) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}