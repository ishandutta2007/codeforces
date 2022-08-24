#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
ll a[maxN];
ll b[maxN];

void bad() {
    cout << "IMPOSSIBLE";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if (n == 1) {
        if (a[1] == b[1]) {
            cout << "SMALL" << endl << 0 << endl;
        }
        else {
            cout << "IMPOSSIBLE";
        }
        return 0;
    }
    const int REV = 0;
    const int PREF = 1;
    vector<pair<int, ll> > ans;
    ll sz = 0;
    while (true) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                ok = false;
                break;
            }
        }
        if (ok) break;
        ok = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[n + 1 - i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.emplace_back(REV, 1);
            break;
        }
        if (b[1] > b[n]) {
            reverse(b + 1, b + n + 1);
            ans.emplace_back(REV, 1);
        }
        assert(b[1] <= b[n]);
        if (n == 2) {
            ll sum_from = b[1] + b[2];
            ll sum_to = a[1] + a[2];
            if (sum_from <= sum_to) bad();
            if (b[1] + (b[2] % b[1]) >= sum_to) {
                ans.emplace_back(PREF, b[2] / b[1]);
                b[2] %= b[1];
                if (b[2] <= 0) bad();
            } else {
                if (sum_from % b[1] != sum_to % b[1]) bad();
                ll moves = (sum_from - sum_to) / b[1];
                b[2] -= moves * b[1];
                if (b[2] <= 0) bad();
                ans.emplace_back(PREF, moves);
            }
        } else {
            ans.emplace_back(PREF, 1);
            sz++;
            for (int i = n; i > 1; i--) {
                b[i] -= b[i - 1];
            }
            for (int i = 1; i <= n; i++) {
                if (b[i] <= 0) bad();
            }
        }
    }
    ll val = 0;
    reverse(ans.begin(), ans.end());
    for (auto &it : ans) {
        if (it.first == PREF) val += it.second;
    }
    ll gg = 0;
    for (auto &it : ans) gg += it.second;
    if (val > 200000) {
        cout << "BIG" << endl;
        cout << val;
        return 0;
    }
    cout << "SMALL" << endl;
    cout << gg << '\n';
    for (auto &it : ans) {
        for (ll v = 0; v < it.second; v++) {
            if (it.first == PREF) cout << "P";
            else cout << "R";
        }
    }
    return 0;
}