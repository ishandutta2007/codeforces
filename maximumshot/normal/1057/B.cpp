#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    vec< int > r(n + 1);
    int res = 0;

    for(int p = 0, i = 1;i <= n;i++) {
        scanf("%d", &r[i]);
        p += r[i];
        r[i] = p - i * 100;
        int j = 0;
        while(j < i && r[j] >= r[i]) j++;
        res = max(res, i - j);
    }

    printf("%d\n", res);

    return 0;
}