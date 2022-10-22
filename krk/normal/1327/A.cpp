#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        printf("%s\n", ll(k) * k <= n && k % 2 == n % 2? "YES": "NO");
    }
    return 0;
}