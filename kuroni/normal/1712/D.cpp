#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int le = 0, ri = INF;
        while (le <= ri) {
            int mi = (le + ri) / 2;
            auto tmp = a;
            int ans = 0;
            for (int& v : tmp) {
                if (v * 2 < mi) {
                    v = INF;
                    ans++;
                }
            }
            int add = 2;
            for (int i = 1; i < n; i++) {
                add = min(add, (tmp[i - 1] < mi) + (tmp[i] < mi));
            }
            ans += add;
            if (ans > k) {
                ri = mi - 1;
            } else {
                le = mi + 1;
            }
        }
        cout << ri << '\n';
    }
}