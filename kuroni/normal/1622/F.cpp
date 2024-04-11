#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
unsigned long long msk[N], fct[N];
bool pr[N], chk[N];
unordered_map<unsigned long long, int> pos;

void init(int n) {
    pos[0] = 1;
    for (int i = 2; i <= n; i++) {
        if (!pr[i]) {
            unsigned long long tmp = rng();
            for (int j = i; j <= n; j += i) {
                pr[j] = true;
                for (int u = j; u % i == 0; u /= i) {
                    msk[j] ^= tmp;
                }
            }
        }
        fct[i] = fct[i - 1] ^ msk[i];
        pos[fct[i]] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    init(n);
    unsigned long long tot = 0;
    for (int i = 1; i <= n; i++) {
        tot ^= fct[i];
    }
    pair<int, vector<int>> ans;
    // direct
    if (n % 2 == 0) {
        if (tot == fct[n / 2]) {
            ans = {1, {n / 2}};
        } else {
            ans = {2, {2, n / 2}};
        }
    } else {
        tot ^= fct[n];
        if (tot == fct[n / 2]) {
            ans = {2, {n / 2, n}};
        } else {
            ans = {3, {2, n / 2, n}};
        }
        tot ^= fct[n];
    }
    // 0 elems
    if (tot == 0) {
        ans = min(ans, {0, {}});
    }
    // 1 elem
    if (pos.count(tot)) {
        ans = min(ans, {1, {pos[tot]}});
    }
    for (int i = 1; i <= n; i++) {
        if (tot == fct[i]) {
            ans = min(ans, {1, {i}});
        }
    }
    // 2 elems
    for (int i = 1; i <= n; i++) {
        if (pos.count(tot ^ fct[i])) {
            ans = min(ans, {2, {i, pos[tot ^ fct[i]]}});
        }
    }
    cout << n - ans.first << '\n';
    for (int i = 1; i <= n; i++) {
        if (find(ans.second.begin(), ans.second.end(), i) == ans.second.end()) {
            cout << i << " ";
        }
    }
}