#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;

int t, n, u;
map<long long, int> ma;

void solve() {
    cin >> n;
    ma.clear();
    int su = 1;
    long long com = 0;
    ma[0] = 1;
    while (n--) {
        cin >> u;
        int zer = (su - ma[-com]) % MOD;
        com += u;
        (ma[u - com] += zer) %= MOD;
        (su += zer) %= MOD;
    }
    cout << (su + MOD) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}