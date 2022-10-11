#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N], tr[N][5];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        fill(tr[i], tr[i] + 5, -1);
        if (!(a[i - 1] < a[i])) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < j; k++) {
                    if (tr[i - 1][j] != -1) {
                        tr[i][k] = j;
                    }
                }
            }
        }
        if (!(a[i - 1] > a[i])) {
            for (int j = 0; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    if (tr[i - 1][j] != -1) {
                        tr[i][k] = j;
                    }
                }
            }
        }
    }
    if (*max_element(tr[n], tr[n] + 5) == -1) {
        return cout << -1, 0;
    } else {
        for (int i = n, j = distance(tr[n], max_element(tr[n], tr[n] + 5)); i > 0; i--) {
            ans.push_back(j + 1);
            j = tr[i][j];
        }
        for (int i = n - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
    }
}