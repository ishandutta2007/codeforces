#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> conv(int x) {
    vector<int> v;
    while (x > 0) {
        v.push_back(x % 7);
        x /= 7;
    }
    if (v.empty()) v.push_back(0);
    return v;
}

bool freq[10];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    vector<int> v1 = conv(n - 1), v2 = conv(m - 1);
    if (v1.size() + v2.size() > 7) {
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            memset(freq, 0, sizeof(freq));
            vector<int> a = conv(i), b = conv(j);
            if (a.size() + 1 < v1.size() || b.size() + 1 < v2.size()) continue;
            if (a.size() < v1.size() && b.size() < v2.size()) continue;
            if (a.size() < v1.size() || b.size() < v2.size()) freq[0] = 1;
            bool bad = 0;
            for (int k : a) {
                if (freq[k]) {
                    bad = 1;
                    break;
                } freq[k] = 1;
            }
            if (bad) continue;
            for (int k : b) {
                if (freq[k]) {
                    bad = 1;
                    break;
                } freq[k] = 1;
            }
            if (!bad) ans++;
        }

    cout << ans << '\n';
}