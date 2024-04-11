#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int s = 1LL * n * (n + 1) / 4;
    if (n % 4 == 0 || n % 4 == 3) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }
    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        if (s >= i) {
            ans.push_back(i);
            s -= i;
        }
    }
    cout << ans.size() << ' ';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
    return 0;
}