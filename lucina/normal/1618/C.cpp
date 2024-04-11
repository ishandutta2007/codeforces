#include<bits/stdc++.h>
using namespace std;
string s[150];
int n;
int64_t a[150];

void solve() {
    cin >> n;
    int64_t g[2]{};
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
        g[i % 2] = gcd(g[i % 2], a[i]);
    }
    for (int i = 0 ; i < 2 ; ++ i) {
        int64_t b = g[i];
        bool ok = true;
        for (int j = 0 ; j < n ; j += 2) {
            if ((i ^ j ^ 1) < n)
                ok &= (a[j ^ i ^ 1] % b > 0);
        }
        if (ok) return cout << b << '\n', void();
    }
    cout << "0\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}