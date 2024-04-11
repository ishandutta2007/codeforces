#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &n);
		if (n % 2050) printf("-1\n");
		else {
			n /= 2050;
			int sum = 0;
			while (n) {
				sum += n % 10;
				n /= 10;
			}
			printf("%d\n", sum);
		}
	}
    return 0;
}