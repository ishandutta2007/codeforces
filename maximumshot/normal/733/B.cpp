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

bool solve() {

    int n;

    scanf("%d", &n);

    vec< pii > a(n);

    int L = 0;
    int R = 0;

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
        L += a[i].first;
        R += a[i].second;
    }

    pii tot = {abs(R - L), 0};

    for(int i = 0;i < n;i++) {
        int tl, tr;
        tl = L - a[i].first + a[i].second;
        tr = R - a[i].second + a[i].first;
        tot = max(tot, {abs(tl - tr), i + 1});
    }

    printf("%d\n", tot.second);

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}