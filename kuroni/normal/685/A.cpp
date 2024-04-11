#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> se;

int log7(int u) {
    int ans = 1, cur = 1, pw = 1;
    while (pw <= u && cur <= 7) {
        ans = cur++;
        pw *= 7;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m; --n; --m;
    int l = log7(n), r = log7(m);
    if (l + r > 7) {
        return cout << 0, 0;
    }
    vector<int> ve;
    for (int i = 0; i < 7; i++) {
        ve.push_back(i);
    }
    do {
        int hr = 0, mi = 0;
        for (int i = 0; i < l; i++) {
            (hr *= 7) += ve[i];
        }
        for (int i = 0; i < r; i++) {
            (mi *= 7) += ve[l + i];
        }
        if (hr <= n && mi <= m) {
            se.insert({hr, mi});
        }
    } while (next_permutation(ve.begin(), ve.end()));
    cout << se.size() << '\n';
}