#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n, a[N];
set<int> se;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        se.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 1; j < i; j++) {
                se.insert(abs(a[i] - a[j]));
            }
        }
        cout << se.size() << '\n';
    }
}