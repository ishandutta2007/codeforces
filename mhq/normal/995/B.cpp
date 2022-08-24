#include <bits/stdc++.h>
using namespace std;
int a[205], n;
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        int x = a[2 * i];
        int y = -1;
        for (int j = 2 * i - 1; j >= 1; j--) {
            if (a[j] == x) {
                y = j;
                break;
            }
        }
        ans += 2 * i - y - 1;
        for (int k = y; k <= 2 * i - 2; k++) {
            swap(a[k], a[k + 1]);
        }
    }
    cout << ans;
    return 0;
}