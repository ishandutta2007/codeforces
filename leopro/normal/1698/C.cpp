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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int positive = count_if(a.begin(), a.end(), [&](int x) { return x > 0; });
    int negative = count_if(a.begin(), a.end(), [&](int x) { return x < 0; });
    if (positive > 2) answer("NO")
    if (negative > 2) answer("NO")
    vector<int> b;
    int zeros = 0;
    for (int &x: a) {
        if (x == 0 && zeros < 3) {
            zeros++;
            b.push_back(x);
        } else if (x != 0) b.push_back(x);
    }
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                if (find(b.begin(), b.end(), b[i] + b[j] + b[k]) == b.end()) answer("NO")
            }
        }
    }
    answer("YES")
}