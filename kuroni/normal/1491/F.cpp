#include <bits/stdc++.h>
using namespace std;

int ask(vector<int> le, vector<int> ri) {
    cout << "? " << le.size() << " " << ri.size() << endl;
    for (int v : le) {
        cout << v << " ";
    }
    cout << endl;
    for (int v : ri) {
        cout << v << " ";
    }
    cout << endl;
    int ret; cin >> ret; return ret;
}

void solve() {
    int n; cin >> n;
    int ind = 0;
    vector<int> le = {1};
    vector<bool> chk(n + 1, false);
    for (int i = 2; i <= n; i++) {
        if (ask(le, {i})) {
            ind = i;
            chk[ind] = true;
            break;
        } else {
            le.push_back(i);
        }
    }
    for (int i = ind + 1; i <= n; i++) {
        if (ask({ind}, {i})) {
            chk[i] = true;
        }
    }
    int oth = 0;
    for (int i = 0; (1 << i) <= (ind - 1); i++) {
        vector<int> le;
        for (int j = 1; j < ind; j++) {
            if (j >> i & 1) {
                le.push_back(j);
            }
        }
        if (le.size() == 0) {
            continue;
        }
        if (ask(le, {ind})) {
            oth ^= (1 << i);
        }
    }
    chk[oth] = true;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!chk[i]) {
            ans.push_back(i);
        }
    }
    cout << "! " << ans.size() << " ";
    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}