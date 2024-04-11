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

int const N = 200005;

int n;
int a[N];
int b[N];
int c[N];

int main() {

    scanf("%d", &n);

    ll tot = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
        tot += b[i];
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &c[i]);
        tot += c[i];
    }

    if(tot % (2ll * n)) {
        puts("-1");
        return 0;
    }

    tot /= (2ll * n);

    for(int i = 1;i <= n;i++) {
        ll value = b[i] + c[i] - tot;
        if(value < 0 || value % n) {
            puts("-1");
            return 0;
        }
        value /= n;
        if(value < 0 || value > c[i]) {
            puts("-1");
            return 0;
        }
        a[i] = (int)value;
    }

    ll delB = 0;
    ll delC = 0;

    for(int cnt, bit = 0;bit <= 30;bit++) {
        cnt = 0;
        for(int i = 1;i <= n;i++) {
            if((a[i] >> bit) & 1) cnt++;
        }
        for(int i = 1;i <= n;i++) {
            if((a[i] >> bit) & 1) {
                delB = (1ll << bit) * cnt;
                delC = (1ll << bit) * n;
            }else {
                delB = 0;
                delC = (1ll << bit) * cnt;
            }
            if(delB > b[i] || delC > c[i]) {
                puts("-1");
                return 0;
            }else {
                b[i] -= delB;
                c[i] -= delC;
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        if(b[i] || c[i]) {
            puts("-1");
            return 0;
        }
    }

    for(int i = 1;i <= n;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}