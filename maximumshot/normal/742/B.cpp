#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1 << 17;

int cnt[N];
int n, x, y;
ll res = 0;

int main() {

    scanf("%d %d", &n, &x);

    for(int i = 0;i < n;i++) {
        scanf("%d", &y);
        res += cnt[y ^ x];
        cnt[y]++;
    }

    printf("%I64d\n", res);

    return 0;
}