#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int X = 1e6 + 5;

int prime[X];

void precalc() {
    fill(prime, prime + X, 1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i * i < X;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < X;j += i) {
            prime[j] = 0;
        }
    }
}

int n, m;

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    int W = n - 1;
    while(!prime[W]) W++;

    printf("%d %d\n", W, W);

    for(int i = 1;i + 1 < n;i++) {
        printf("%d %d %d\n", i, i + 1, 1);
    }

    printf("%d %d %d\n", n - 1, n, W - n + 2);

    m -= (n - 1);

    for(int i = 1;i <= n && m > 0;i++) {
        for(int j = i + 2;j <= n && m > 0;j++) {
            printf("%d %d %d\n", i, j, W + 1);
            m--;
        }
    }

    return 0;
}