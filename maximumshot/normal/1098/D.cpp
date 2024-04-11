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

const int N = 1e5 + 5;
const int X = 1e6;

const int LOG = 35;

multiset< int > Q[LOG];
ll sm[LOG];

int get_biggest_bit(int x) {
    for(int j = LOG - 1;j >= 0;j--) {
        if((1ll << j) & x) {
            return j;
        }
    }
}

int query() {
    ll pref = 0;
    int res = 0;
    for(int j = 0;j < LOG;j++) {
        if(!Q[j].empty() && *Q[j].begin() > 2 * pref) {
            res++;
        }
        pref += sm[j];
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int q;

    scanf("%d", &q);

    int tot = 0;
    for(int x, iter = 0;iter < q;iter++) {
        char op;
        scanf(" %c %d", &op, &x);
        int bl = get_biggest_bit(x);
        if(op == '+') {
            tot++;
            Q[bl].insert(x);
            sm[bl] += x;
        }else { // op == '-'
            tot--;
            Q[bl].erase(Q[bl].lower_bound(x));
            sm[bl] -= x;
        }
        printf("%d\n", tot - query());
    }

    return 0;
}