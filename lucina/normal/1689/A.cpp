#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;


void solve() {
    int n, m, k;
    string a, b;
    string c;

    cin >> n >> m >> k >> a >> b;

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());

    int used = 0, w = 0;

    while (!a.empty() && !b.empty()) {
        if (used == k) {
            if (w == 0) c += b.back(), b.pop_back();
            else c += a.back(), a.pop_back();
            used = 1, w ^= 1;
            continue;
        }
        if (a.back() < b.back()) {
            c += a.back(), a.pop_back();
            used = w == 0 ? used + 1 : 1;
            w = 0;
        } else {
            c += b.back(), b.pop_back();
            used = w == 1 ? used + 1 : 1;
            w = 1;
        }

    }
    cout << c << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    +_+ So bored lately.
*/