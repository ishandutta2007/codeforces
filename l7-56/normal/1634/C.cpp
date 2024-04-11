#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

void work() {
    int n,k;
    scanf("%d%d", &n, &k);
    if ((n & 1) && k > 1) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < k; ++j)
            printf("%d%c", i + n * j, " \n"[j == k - 1]);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) work();
	return 0;
}