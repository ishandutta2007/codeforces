#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int u; cin >> u;
            if (u == 0) {
                zeros++;
            } else {
                a.push_back(u);
            }
        }
        vector<int> nxt;
        while (a.size() > 1) {
            if (zeros > 0) {
                nxt.push_back(a[0]);
                zeros--;
            }
            for (int i = 1; i < a.size(); i++) {
                if (a[i] - a[i - 1] == 0) {
                    zeros++;
                } else {
                    nxt.push_back(a[i] - a[i - 1]);
                }
            }
            sort(nxt.begin(), nxt.end());
            swap(a, nxt); nxt.clear();
        }
        cout << (a.empty() ? 0 : a[0]) << '\n';
    }
}