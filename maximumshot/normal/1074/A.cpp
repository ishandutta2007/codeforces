#include <bits/stdc++.h>

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

    int n, m;

    scanf("%d %d", &n, &m);

    vec< int > ver(n);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        ver[i] = x;
    }

    sort(ALL(ver));

    vec< int > hor(m);

    for(int x1, x2, y, i = 0;i < m;i++) {
        scanf("%d %d %d", &x1, &x2, &y);
        if(x1 == 1)
            hor[i] = x2;
    }

    sort(ALL(hor));

    n = (int)ver.size();
    m = (int)hor.size();

    ver.push_back(inf);

    int res = inf;

    for(int i = 0;i <= n;i++) {
        res = min(res, i + int(hor.end() - lower_bound(ALL(hor), ver[i])));
    }

    printf("%d\n", res);

    return 0;
}