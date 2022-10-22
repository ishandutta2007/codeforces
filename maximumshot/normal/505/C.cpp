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

const int X = 3e4 + 1;

int cnt[X];
//unordered_map< int, int > mem[X];
gp_hash_table< int, int > mem[X];
gp_hash_table< int, int > mp;

int rec(int pos, int last) {
    if(pos >= X) return 0;
//    if(mem[pos].count(last)) return mem[pos][last];
    if(mem[pos].find(last) != mem[pos].end()) return mem[pos][last];
    int res = cnt[pos];
    for(int dx = -1;dx <= 1;dx++) {
        int jump = last + dx;
        if(jump <= 0) continue;
        res = max(res, cnt[pos] + rec(pos + jump, jump));
    }
    return mem[pos][last] = res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, d;

    scanf("%d %d", &n, &d);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    printf("%d\n", rec(d, d));

    return 0;
}