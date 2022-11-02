#include <bits/stdc++.h>

using namespace std;

const int maxn = 200100;

int n;
pair<int, int> ar[2 * maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ar[2 * i] = make_pair(l, 1);
        ar[2 * i + 1] = make_pair(r + 1, -1);
    }
    sort(ar, ar + 2 * n);

    int num = 0;
    for (int i = 0; i < 2 * n; i++) {
        num += ar[i].second;
        if (num > 2) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}