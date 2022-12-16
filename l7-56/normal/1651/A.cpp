#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		printf("%d\n", (1 << n) - 1);
	}
	return 0;
}