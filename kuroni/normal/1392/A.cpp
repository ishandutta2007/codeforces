#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << (*min_element(a + 1, a + n + 1) == *max_element(a + 1, a + n + 1) ? n : 1) << '\n';
    }
}