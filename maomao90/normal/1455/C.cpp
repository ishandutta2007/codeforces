#include <bits/stdc++.h>
using namespace std;

int t;
int x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &x, &y);
		printf("%d %d\n", x - 1, y);
	}
	return 0;
}