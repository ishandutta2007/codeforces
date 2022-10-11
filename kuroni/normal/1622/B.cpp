#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first; a[i].second = i;
        }
        string s; cin >> s;
        vector<vector<pair<int, int>>> b(2);
        for (int i = 0; i < n; i++) {
            b[s[i] - '0'].push_back(a[i]);
        }
        sort(b[0].begin(), b[0].end()); sort(b[1].begin(), b[1].end()); b[0].insert(b[0].end(), b[1].begin(), b[1].end());
        for (int i = 0; i < n; i++) {
            b[0][i].first = i + 1;
        }
        sort(b[0].begin(), b[0].end(), [](const pair<int, int> u, const pair<int, int> v) {
            return u.second < v.second;
        });
        for (int i = 0; i < n; i++) {
            cout << b[0][i].first << " \n"[i == n - 1];
        }
    }
}