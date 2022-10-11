#include <bits/stdc++.h>
using namespace std;
    
const int N = 2E5 + 5;
    
int n, a[N];
map<int, int> cnt;
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    pair<int, int> mx = {0, 0};
    for (int i = 1; i <= n; i++) {
        mx = max(mx, {cnt[a[i]], a[i]});
    }
    auto [cn, val] = mx;
    cout << n - cn << '\n';
    for (int i = 1; i <= n; i++) {
        if (a[i] == val) {
            for (int j = i + 1; a[j] != val && j <= n; j++) {
                cout << (a[j] < val ? 1 : 2) << " " << j << " " << j - 1 << '\n';
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == val) {
            for (int j = i - 1; j >= 1; j--) {
                cout << (a[j] < val ? 1 : 2) << " " << j << " " << j + 1 << '\n';
            }
            break;
        }
    }
}