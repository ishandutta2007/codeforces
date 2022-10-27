#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set <int> brute;
    for (int64_t i = 1 ; i * i <= n ; ++ i) {
        if (i * i * i <= n) {
            brute.insert(i * i * i);
        }
        brute.insert(i * i);
    }
    cout << brute.size() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}