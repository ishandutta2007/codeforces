#include <cstdio>

using namespace std;

int t;
int n, a[5005];

int main() {
	scanf("%d", &t);
	while (t--) {
		bool yes = false;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) {
			for (int j = i + 2; j < n; j++) {
				if (a[i] == a[j]) yes = true;
			}
		}
		if (yes) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}