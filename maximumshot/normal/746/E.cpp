#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    vec< int > a(n);
    vec< char > mark(n);
    set< int > q;
    int c[2] = {0, 0};
    int res = 0;

    map< int, int > H;

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        H[ -a[i] ] = i;
    }

    for(auto iter : H) {
        int value, id;
        value = -iter.first;
        id = iter.second;
        if( q.count(value) || c[value % 2] == n / 2) continue;
        c[ value % 2 ]++;
        q.insert( value );
        mark[ id ] = 1;
    }

    for(int i = 0;i < n;i++) res += !mark[i];

    int mn[2] = { 2, 1 };

    for(int i = 0;i < n;i++) {
        if( mark[i] ) {
            continue;
        }
        int ty = c[0] < c[1] ? 0 : 1;
        while(q.count(mn[ty])) mn[ty] += 2;
        if(mn[ty] > m) {
            puts("-1");
            return 0;
        }
        c[ty]++;
        a[i] = mn[ty];
        q.insert( a[i] );
    }

    printf("%d\n", res);

    for(int i = 0;i < n;i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}