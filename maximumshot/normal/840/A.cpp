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

    int m;

    scanf("%d", &m);

    vec< pii > a(m), b(m);

    for(int i = 0;i < m;i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    for(int i = 0;i < m;i++) {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }

    sort(ALL(a));
    sort(ALL(b));
    reverse(ALL(b));

    vec< int > res(m);

    for(int i = 0;i < m;i++) {
        res[b[i].second] = a[i].first;
    }

    for(int i = 0;i < m;i++) {
        printf("%d ", res[i]);
    }

    printf("\n");

    return 0;
}