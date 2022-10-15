#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }
#define answerExit(answer) { cout << (answer) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (n > m) answer("NO");
    if (n == 1) {
        cout << "YES\n" << m << '\n';
        return;
    }
    if (n % 2 == 0 && m % 2) answer("NO");
    cout << "YES\n";
    int k = 0;
    for (int i = 0; i < ((n - 1) & ~1); ++i) {
        cout << "1 ";
        k = i + 1;
    }
    if (n - k == 2) cout << ((m - k) / 2) << ' ' << ((m - k) / 2) << '\n'; else cout << m - k << '\n';
}