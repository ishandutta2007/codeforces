#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int n,sum;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a; scanf("%d", &a);
		sum += a;
	}
	printf("%d\n", sum);
	return 0;
}