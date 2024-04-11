#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int sum(int a, int b) {
    return (a + b) % mod;
}

inline int mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int const MAX_VAL = 1000005;
int const LOG = 30;

bool prime[MAX_VAL];
vec< int > a[MAX_VAL];
int f[MAX_VAL][LOG];

void init() {
    for(int i = 2;i < MAX_VAL;i++) prime[i] = 1;
    for(int i = 2;i * i < MAX_VAL;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < MAX_VAL;j += i) prime[j] = 0;
    }
    for(int i = 2;i < MAX_VAL;i++) {
        if(!prime[i]) continue;
        for(int c, x, j = i;j < MAX_VAL;j += i) {
            x = j;
            c = 0;
            while(x % i == 0) {
                x /= i;
                c++;
            }
            a[j].push_back(c);
        }
    }
    f[0][0] = 1;
    for(int i = 1;i < LOG;i++) f[0][i] = 2;
    for(int r = 1;r < MAX_VAL;r++) {
        for(int pr = 0, i = 0;i < LOG;i++) {
            pr = sum(pr, f[r - 1][i]);
            f[r][i] = pr;
        }
    }
}

int main() {

    init();

    int q;
    scanf("%d", &q);

    for(int r, n, iter = 0;iter < q;iter++) {
        scanf("%d %d", &r, &n);
        int res = 1;
        for(int i : a[n]) {
            res = mul(res, f[r][i]);
        }
        printf("%d\n", res);
    }

    return 0;
}