#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t a[nax];

bool solve() {
    cin >> n;
    int64_t sum = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        sum += a[i];
        a[i] += a[i - 1];
    }
    if (sum != 0) return false;
    bool found = false;
    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] < 0) return false;
        if (a[i] == 0 && !found) found = true;
        if (a[i] > 0 && found) return false;
    }
    return true;

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/**
    CF800~ Rarely participated in 7xx round.
*/