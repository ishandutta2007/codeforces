#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

LL n, p;

bool inline check(int cnt, LL k) {
    if (k <= 0) return 0;
    int c = 0;
    for (int i = 0; i < 63; i++) 
        if (k >> i & 1) c++;
    return c <= cnt && cnt <= k;
}

int main() {
    scanf("%lld%lld", &n, &p);
    int ans = -1;
    for (int i = 1; i <= 64; i++) {
        if (check(i, n - i * p)) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}