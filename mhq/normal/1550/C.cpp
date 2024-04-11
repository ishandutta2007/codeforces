#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5 + 10;
int a[maxN];
int main() {
 //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int len = 1; len <= 5 && i + len - 1 <= n; len++) {
                int l = i;
                int r = i + len - 1;
                bool ok = true;
                for (int x = l; x <= r; x++) {
                    for (int y = x + 1; y <= r; y++) {
                        for (int z = y + 1; z <= r; z++) {
                            if (a[x] <= a[y] && a[y] <= a[z]) {
                                ok = false;
                                break;
                            }
                            if (a[x] >= a[y] && a[y] >= a[z]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
                if (!ok) break;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}