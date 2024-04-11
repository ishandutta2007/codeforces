#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n, a;

    scanf("%d %d", &n, &a);

    if(n == 1) {
        printf("0\n");
        return true;
    }

    vec< int > x(n);

    for(int i = 0;i < n;i++) {
        scanf("%d", &x[i]);
    }

    sort(ALL(x));

    int res = min(abs(a - x[0]), abs(a - x[n - 1])) + x[n - 1] - x[0];
    res = min(res, min(abs(a - x[1]), abs(a - x[n - 1])) + x[n - 1] - x[1]);
    res = min(res, min(abs(a - x[0]), abs(a - x[n - 2])) + x[n - 2] - x[0]);

    printf("%d\n", res);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}