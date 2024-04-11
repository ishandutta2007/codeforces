#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int h;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> h;
    int cur = -1;
    bool ok = false;
    int ind = -1;
    for (int i = 0; i <= h; i++) {
        cin >> a[i];
        if (a[i] > 1 && cur > 1) {
            ok = true;
            ind = i;
        }
        cur = a[i];
    }
    if (!ok) {
        cout << "perfect";
        return 0;
    }
    cout << "ambiguous" << '\n';
    cout << 0 << " ";
    int sum = 0;
    for (int i = 1; i <= h; i++) {
        sum += a[i - 1];
        for (int j = 1; j <= a[i]; j++) {
            cout << sum << " ";
        }
    }
    sum = 0;
    cout << '\n';
    cout << 0 << " ";
    for (int i = 1; i <= h; i++) {
        sum += a[i - 1];
        for (int j = 1; j <= a[i]; j++) {
            if (i != ind) {
                cout << sum << " ";
            }
            else {
                if (j == 1) cout << sum << " ";
                else cout << sum - 1 << " ";
            }
        }
    }
    return 0;
}