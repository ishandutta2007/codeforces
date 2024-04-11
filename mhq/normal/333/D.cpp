#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005][1005];
bool used[1005][1005];
bool f(int x) {
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            used[i][j] = false;
        }
    }
    vector < int > need;
    for (int i = 1; i <= n; i++) {
        need.clear();
        for (int j = 1; j <= m; j++) {
            if (a[i][j] >= x) need.push_back(j);
        }
        for (int j = 0; j < need.size(); j++) {
            for (int k = j + 1; k < need.size(); k++) {
                if (used[need[j]][need[k]]) {
                    return true;
                }
                used[need[j]][need[k]] = true;
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    int l = 0;
    int r = (int)1e9 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}