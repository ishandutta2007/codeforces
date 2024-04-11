#include <bits/stdc++.h>
using namespace std;


void work() {
	int x, y;
	scanf("%d%d", &x, &y);
	if (y >= 2 * x) printf("%d %d\n", x, x * 2);
	else puts("-1 -1");

}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) work();
}