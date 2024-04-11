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

const int N = 1005;

int n, m;
int a[N];
int b[N];

bool check(ld x) {
    for(int i = 1;i <= n;i++) {
        if((m + x) > x * a[i]) {
            return false;
        }else {
            x -= (m + x) / a[i];
        }
        if((m + x) > x * b[i]) {
            return false;
        }else {
            x -= (m + x) / b[i];
        }
    }
    return true;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        if(a[i] == 1) {
            puts("-1");
            return 0;
        }
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
        if(b[i] == 1) {
            puts("-1");
            return 0;
        }
    }

    ld bl = 0.0;
    ld br = 1e10;
    ld bm;

    for(int iter = 0;iter < 500;iter++) {
        bm = 0.5 * (bl + br);
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    printf("%.10lf\n", double(bl));

    return 0;
}