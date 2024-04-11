#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

void go(vector<int> &a, int &z) {
    if (z == 0) {
        vector<int> b(a.size() - 1);
        for (int i = 1; i < a.size(); ++i) b[i - 1] = a[i] - a[i - 1];
        sort(b.rbegin(), b.rend());
        while (b.size() >= 1 && b[b.size() - 1] == 0) {
            z++;
            b.pop_back();
        }
        reverse(b.begin(), b.end());
        a = b;
        return;
    } else {
        vector<int> b(a.size(), a[0]);
        for (int i = 1; i < a.size(); ++i) b[i] = a[i] - a[i - 1];
        sort(b.rbegin(), b.rend());
        --z;
        while (b.size() >= 1 && b[b.size() - 1] == 0) {
            z++;
            b.pop_back();
        }
        reverse(b.begin(), b.end());
        a = b;
        return;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int z = 0;
    while (a.size() > 1) go(a, z);
    cout << (a.size() == 1 ? a[0] : 0) << '\n';
}