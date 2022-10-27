#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {

    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    bool used[n + 1]{};

    int sum = 0;

    while (true) {
        if (count(used + 1, used + 1 + n, true) == n) break;
        int new_sum = 0, idx = -1;
        for (int i = 1 ; i <= n ; ++ i) {
            if (used[i]) continue;
            if ((sum | a[i]) > new_sum) {
                new_sum = sum | a[i];
                idx = i;
            }
        }
        if (sum == new_sum) {
            for (int i = 1 ; i <= n ; ++ i) {
                if (!used[i]) {
                    cout << a[i] << ' ';
                }
            }
            break;
        }
        used[idx] = true;
        cout << a[idx] << ' ';
        sum = new_sum;
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}