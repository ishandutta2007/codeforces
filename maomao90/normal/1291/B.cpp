#include <cstdio>
#include <algorithm>

using namespace std;

int t;
int n;
int a[300005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		bool increasing = true;
		int prev = -1;
		for (int i = 0; i < n; i++) {
			if (increasing) {
				if (a[i] < i) {
					increasing = false;
					prev = min(a[i], a[i - 1] - 1);
				}
			} else {
				if (a[i] >= prev) prev--;
				else prev = a[i];
			}
		}
		if (prev < 0 && !increasing) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}