#ifdef debug
#define _GLIBCXX_DEBUG
#endif

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

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, h;
pii a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &h);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }

    sort(a + 1, a + n + 1);

    int res = 0;
    int cur = 0;
    int len = 0;

    for(int j = n, i = n;i >= 1;i--) {
        cur += a[i].second - a[i].first;
        if(i < n) len += a[i + 1].first - a[i].second;
        while(len >= h) {
            len -= (a[j].first - a[j - 1].second);
            cur -= (a[j].second - a[j].first);
            j--;
        }
        res = max(res, cur + h);
    }

    printf("%d\n", res);

    return 0;
}