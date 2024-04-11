#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, k;
int a[N];

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    int q = k;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        a[i] %= k;
        q = gcd(q, a[i]);
    }

    if(!q) {
        printf("1\n0\n");
        return 0;
    }

    printf("%d\n", (k - 1) / q + 1);

    for(int i = 0;i < k;i += q) {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}