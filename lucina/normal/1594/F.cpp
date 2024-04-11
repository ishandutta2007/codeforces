#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
using ll = int64_t;
ll s, k, n;
bool solve() {
    cin >> s >> n >> k;
    if (k > s) return false;
    if (k == s) return true;
    ll y = s / (2 * k);
    ll go = y * k;
    return n > go+ min(k, s - 2 * go + 1) - 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}