#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    for(int bl, br, bm, bp, a, b, iter = 0;iter < n;iter++) {
        scanf("%d %d", &a, &b);
        bl = 0;
        br = 1000 * 1000;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(1ll * bm * bm * bm > 1ll * a * b) {
                br = bm - 1;
            }else {
                bl = bm;
            }
        }
        if(1ll * bl * bl * bl == 1ll * a * b) {
            bp = bl;
        }else if(1ll * br * br * br == 1ll * a * b) {
            bp = br;
        }else {
            puts("No");
            continue;
        }
        if(a % bp || b % bp) {
            puts("No");
        }else {
            puts("Yes");
        }
    }

    return 0;
}