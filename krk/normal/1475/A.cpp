#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &n);
		while (n % 2 == 0) n /= 2;
		printf("%s\n", n > 1? "YES": "NO");
	}
    return 0;
}