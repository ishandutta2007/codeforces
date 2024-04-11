#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int x[205];
bool ok[205];
bool nok[205];
int timer;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) ok[i] = false;
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
        ok[x[i]] = true;
    }
    timer = 0;
    while (1) {
        timer++;
        bool rok = true;
        for (int i = 1; i <= n; i++) nok[i] = ok[i];
        for (int i = 1; i <= n; i++) {
            if (!ok[i]) {
                rok = false;
                break;
            }
        }
        if (rok) break;
        for (int i = 1; i <= n; i++) {
            if (nok[i + 1] && i + 1 <= n) ok[i] = true;
            if (nok[i - 1] && i >= 2) ok[i] = true;
        }
    }
    cout << timer << '\n';
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}