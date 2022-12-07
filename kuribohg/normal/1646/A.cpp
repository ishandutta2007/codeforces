#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
int T, n;
LL s, sum[1000010];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%I64d", &n, &s);
        printf("%I64d\n", s/((LL)n*(LL)n));
    }

    return 0;
}