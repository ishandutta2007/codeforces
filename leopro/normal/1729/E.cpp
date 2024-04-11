#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << "! " << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    ll ans[8][8];
    for (int i = 1; i <= 7; ++i)
        for (int j = 1; j <= 7; ++j)
            if (i != j) {
                cout << "? " << i << ' ' << j << endl;
                cin >> ans[i][j];
            }
    //for (int i = 1; i <= 7; ++i) for (int j = 1; j < i; ++j) if (ans[i][j] != ans[j][i]) answer(ans[i][j] + ans[j][i]);
    map<ll, int> w;
    for (int i = 1; i <= 7; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (ans[i][j] == -1) answer(i - 1);
            for (int k = 1; k <= j; ++k) {
                ll a[3] = {ans[i][j], ans[i][k], ans[j][k]};
                sort(a, a + 3);
                if (a[0] + a[1] != a[2]) {
                    w[a[0] + a[1] + a[2]]++;
                    w[-a[0] + a[1] + a[2]]++;
                }
            }
        }
    }
    vector<pair<ll, int>> x(w.begin(), w.end());
    sort(x.begin(), x.end(), [](auto p, auto q) { return p.second > q.second; });
    cout << "! " << x[0].first << '\n';
}