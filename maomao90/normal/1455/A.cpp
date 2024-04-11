#include <bits/stdc++.h>
using namespace std;

int t;
char n[105];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf(" %s", n);
		printf("%d\n", (int) strlen(n));
	}
	return 0;
}