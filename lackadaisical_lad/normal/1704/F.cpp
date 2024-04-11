#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

const int N = 100;
const int P = 34;
int g[N + P];

int grundy(int len) {
    if (len < N + P)
        return g[len];
    return g[(len - N) % P + N];
}   

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntR = count(s.begin(), s.end(), 'R');
    int cntB = count(s.begin(), s.end(), 'B');
    int bal = cntR - cntB;
    int kek = 0;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && s[j] != s[j - 1])
            ++j;
        kek ^= grundy(j - i);
        i = j;
    }
    if (bal > 0)
        cout << "Alice\n";
    else if (bal < 0)
        cout << "Bob\n";
    else
        cout << (kek ? "Alice\n" : "Bob\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N + P; i++) {
        vector<int> used(N + P + 5);
        for (int j = 0; j + 1 < i; j++)
            used[g[j] ^ g[i - j - 2]] = 1;
        while (used[g[i]])
            g[i]++;
    }
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}