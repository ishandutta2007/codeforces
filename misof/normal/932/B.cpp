// another fine solution by misof
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

vector<int> buckets[10];
vector<int> memo(1000047,-1);

int g(int n) {
    if (n < 10) return n;
    if (memo[n] != -1) return memo[n];
    int product = 1;
    while (n) {
        int d = n % 10;
        n /= 10;
        if (d != 0) product *= d;
    }
    memo[n] = g(product);
    return memo[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int n=1; n<=1000000; ++n) buckets[ g(n) ].push_back(n);
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r, k;
        cin >> l >> r >> k;
        auto it1 = lower_bound( buckets[k].begin(), buckets[k].end(), l );
        auto it2 = upper_bound( buckets[k].begin(), buckets[k].end(), r );
        cout << (it2 - it1) << "\n";
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread