#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll tot;
int sum;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int a, b; scanf("%d %d", &a, &b);
        a--;
        tot += b;
        sum = (sum + ll(a) * b) % n;
    }
    if (tot > n) printf("-1\n");
    else if (tot < n) printf("1\n");
    else {
        int nd = ll(n - 1) * n / 2 % n;
        printf("%d\n", sum == nd? 1: -1);
    }
    return 0;
}