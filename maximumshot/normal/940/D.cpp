#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

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

    int l = -inf;
    int r = +inf;

    vec< int > a(n + 1);
    vec< char > b(n + 1);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    int any1 = 0;
    for(int i = 1;i <= n;i++) {
        scanf(" %c", &b[i]);
        if(b[i] == '1') {
            any1 = 1;
        }
    }

    if(!any1) {
        printf("%d %d\n", -inf, +inf);
        return 0;
    }

    for(int i = 5;i <= n;i++) {
        if(b[i] == b[i - 1]) continue;
        for(int q = 0;q <= 4;q++) {
            if(b[i] == '1') {
                l = max(l, a[i - q] + 1);
            }else {
                r = min(r, a[i - q] - 1);
            }
        }
    }

    printf("%d %d\n", l, r);

    return 0;
}