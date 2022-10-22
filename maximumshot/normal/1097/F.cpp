#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 7001;
const int N = 1e5 + 5;

bitset< X > bs[N];
bitset< X > mu[X];
bitset< X > ff[X];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    for(int d = X - 1;d >= 1;d--) {
        mu[d][d] = 1;
        for(int k = 2 * d;k < X;k += d) {
            mu[d] ^= mu[k];
        }
    }

    for(int i = 1;i < X;i++) {
        for(int j = i;j < X;j += i) {
            ff[j][i] = 1;
        }
    }

    int n, q;

    scanf("%d %d", &n, &q);

    for(int iter = 0;iter < q;iter++) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int x, v;
            scanf("%d %d", &x, &v);
            bs[x] = ff[v];
        }else if(type == 2) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            bs[x] = bs[y] ^ bs[z];
        }else if(type == 3) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            bs[x] = bs[y] & bs[z];
        }else if(type == 4) {
            int x, v;
            scanf("%d %d", &x, &v);
            printf("%d", int( (bs[x] & mu[v]).count() & 1 ));
        }
    }

    printf("\n");



    return 0;
}