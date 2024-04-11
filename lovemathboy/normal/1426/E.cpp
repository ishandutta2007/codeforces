#include <bits/stdc++.h>
using namespace std;

int n;
int a1, a2, a3;
int b1, b2, b3;

int main() {
	scanf("%d", &n);
	scanf("%d %d %d", &a1, &a2, &a3);
	scanf("%d %d %d", &b1, &b2, &b3);
	int maxi = min(a1, b2) + min(a2, b3) + min(a3, b1);
	int mini = max(0, a1 - b1 - b3) + max(0, a2 - b2 - b1) + max(0, a3 - b3 - b2);
	printf("%d %d\n", mini, maxi);
	return 0;
}