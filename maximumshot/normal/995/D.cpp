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

const int N = 18;

int n, r;
int a[1 << N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &r);

    int tot = 1 << n;
    ll sum = 0;

    for(int i = 0;i < tot;i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("%.10lf\n", double(1.0 * sum / tot));

    for(int pos, val, iter = 0;iter < r;iter++) {
        scanf("%d %d", &pos, &val);
        sum -= a[pos];
        a[pos] = val;
        sum += a[pos];
        printf("%.10lf\n", double(1.0 * sum / tot));
    }

    return 0;
}