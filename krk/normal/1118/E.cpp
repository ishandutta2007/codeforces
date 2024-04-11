#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    if (ll(k) * (k - 1) < n) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 1; i < k && n > 0; i++)
            for (int j = 0; j < k && n > 0; j++) {
                int a = j + 1;
                int b = (j + i) % k + 1;
                printf("%d %d\n", a, b);
                n--;
            }
    }
    return 0;
}