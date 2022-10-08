#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, l, k;
string s, t[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> k >> s;
    sort(s.begin(), s.end());
    int ind = 0, pt = 1;
    for (int i = 1; i <= l; i++) {
        for (int j = pt; j <= k; j++) {
            t[j].push_back(s[ind++]);
            if (t[j - 1].size() == t[j].size() && t[j - 1].back() != t[j].back()) {
                pt = j;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = t[i].size(); j < l; j++) {
            t[i].push_back(s[ind++]);
        }
        cout << t[i] << '\n';
    }
}