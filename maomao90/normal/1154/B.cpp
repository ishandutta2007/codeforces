#include <cstdio>
#include <set>

using namespace std;

int n;
set <int> distinct;
int diff = -1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		distinct.insert(a);
	}
	if (distinct.size() > 3) {
		printf("-1\n");
		return 0;
	}
	if (distinct.size() == 1) {
        printf("0\n");
        return 0;
	}
	int prev = -1;
	for (int i : distinct) {
		if (prev == -1) prev = i;
		else {
			if (diff != -1 && i - prev != diff) {
				printf("-1\n");
				return 0;
			} else {
				diff = i - prev;
                prev = i;
			}
		}
	}
	if (distinct.size() == 3) {
		printf("%d\n", diff);
		return 0;
	}
	if (diff % 2 == 0) {
		printf("%d\n", diff / 2);
	} else {
		printf("%d\n", diff);
	}
	return 0;
}