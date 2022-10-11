#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int n, k, a[N];
map<long long, pair<int, int>> ma;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
        }
        long long su = accumulate(a + 1, a + n + 1, 0LL);
        for (int j = 1; j <= n; j++) {
            if (ma.count(su - a[j]) == 0 || ma[su - a[j]].first == i) {
                ma[su - a[j]] = {i, j};
            } else {
                pair<int, int> oth = ma[su - a[j]];
                cout << "YES\n";
                cout << oth.first << " " << oth.second << '\n' << i << " " << j << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
}