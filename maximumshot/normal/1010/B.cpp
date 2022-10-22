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

int ask(int y) {
    printf("%d\n", y);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int a[40], cur, m, n;

int task(int y) {
    printf("%d\n", y);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if(!a[cur]) res = -res;
    if(++cur == n) cur = 0;
    return res;
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &m, &n);

    for(int i = 0;i < n;i++) {
        int t = ask(1);
        if(t == 0) {
            return 0;
        }
        if(t == 1) {
            a[i] = 1;
        }
    }

    int bl = 1;
    int br = m + 1;

    while(br - bl > 1) {
        int bm = (bl + br) / 2;
        int t = task(bm);
        if(t == 0) return 0;
        if(t == 1) {
            bl = bm;
        }else {
            br = bm;
        }
    }

    return 0;
}