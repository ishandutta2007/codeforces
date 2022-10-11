#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    const int INF = n * m + n + m + 228;
    vector<int> pref(n * m + 1), last(m, INF);
    for (int i = n * m - 1; i >= 0; i--) {
        if (s[i] == '0') continue;
        int dist = min(n, (last[i % m] - i) / m);
        pref[i]++;
        pref[min(n * m, i + dist * m)]--;
        last[i % m] = i;
    }

    vector<int> x(n * m, -1);
    for (int i = n * m - 1, last = INF; i >= 0; i--) {
        if (s[i] == '0') continue;
        x[i] = min(last - i, m);
        last = i;
    }

    vector<int> to_add(m);
    for (int i = 0; i < n * m; i++) {
        if (x[i] != -1) to_add[i % m]++;
        pref[i] += to_add[i % m];
        if (x[i] != -1) to_add[(i + x[i]) % m]--;
    }

    for (int i = 0; i < n * m; i++) {
        pref[i + 1] += pref[i];
        cout << pref[i] << " \n"[i == n * m - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}