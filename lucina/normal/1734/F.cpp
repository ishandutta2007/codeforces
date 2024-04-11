#include<bits/stdc++.h>
using namespace std;
using ll = __int128_t;
map <ll, int64_t> memo;

int64_t solve(int64_t pref, int64_t shift, int64_t s) {
    ll c = (ll(pref) << 62) + shift;
    if (memo.count(c)) return memo[c];
    if (shift == 0) {
        return pref;
    }
    while (s >= shift + pref) s >>= 1;
    if (s <= shift) {
        return memo[c] = pref - solve(pref, shift - s, s);
    }
    return memo[c] = solve(s - shift, shift, s) + pref + shift - s    -solve(pref + shift - s, s - shift, s);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;


    for (cin >> T ; T -- ;) {
        memo.clear();
        int64_t shift, l;
        cin >> shift >> l;
        cout << l - solve(l, shift, 1ll << 62) << '\n';
        assert(memo.size() <= 250);
    }

}