#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &a, &b, &n);
		int res = 1;
		while (a % 2 == 0) { a /= 2; res *= 2; }
		while (b % 2 == 0) { b /= 2; res *= 2; }
		printf("%s\n", res >= n? "YES": "NO");
	}
    return 0;
}