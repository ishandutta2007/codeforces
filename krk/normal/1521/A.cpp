#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int main()
{
	scanf("%d", &T);
	while (T--) {
		int A, B; scanf("%d %d", &A, &B);
		if (B == 1) printf("NO\n");
		else {
			printf("YES\n");
			if (B == 2)
				printf("%I64d %I64d %I64d\n", ll(A), 3ll * ll(A), 4ll * ll(A));
			else printf("%I64d %I64d %I64d\n", ll(A), ll(B - 1) * A, ll(A) * B);
		}
	}
    return 0;
}