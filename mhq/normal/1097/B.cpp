#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
set < char > x1, x2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > all(n);
    for (int i = 0; i < n; i++) {
        cin >> all[i];
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                s += all[j];
            }
            else {
                s -= all[j];
            }
        }
        s = ((s + 360) % 360 + 360) % 360;
        if (s == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}