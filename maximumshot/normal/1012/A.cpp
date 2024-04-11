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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    if(n == 1) {
        puts("0");
        return 0;
    }

    vec< int > a(2 * n);

    for(int i = 0;i < n + n;i++) {
        scanf("%d", &a[i]);
    }

    sort(ALL(a));

    ll res = LLONG_MAX;

    for(int i = n - 1;i < n + n;i++) {
        int lx = a[0], ly, ry;
        int rx = a[i];
        if(i + 1 == n + n) {
            for(int j = 1;j < n;j++) {
                ly = a[j];
                ry = a[j + n - 1];
                if(1ll * (ry - ly) * (rx - lx) < res) {
                    res = 1ll * (ry - ly) * (rx - lx);
                }
            }
        }else {
            ly = a[i + 1];
            ry = a[n + n - 1];
            if(i > n - 1) ly = a[n - 1];
            if(1ll * (ry - ly) * (rx - lx) < res) {
                res = 1ll * (ry - ly) * (rx - lx);
            }
        }
    }

    printf("%lld\n", res);

    return 0;
}