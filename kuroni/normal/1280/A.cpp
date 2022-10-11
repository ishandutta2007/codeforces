#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5, MOD = 1E9 + 7;

int t, x;
string s;

void solve() {
    cin >> x >> s;
    long long ans = s.size(), rig = s.size();
    for (int i = 0; i < x; i++) {
        rig--;
        int n = s.size();
        for (int j = 0; j < s[i] - '1'; j++) {
            for (int k = i + 1; k < n && s.size() < x; k++) {
                s.push_back(s[k]);
            }
        }
        (ans += rig * (s[i] - '1')) %= MOD;
        (rig *= (s[i] - '0')) %= MOD;
    }
    cout << (ans + MOD) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}