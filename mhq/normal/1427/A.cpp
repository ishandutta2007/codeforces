#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a[55];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            sort(a + 1, a + n + 1);
            if (sum > 0) {
                reverse(a + 1, a + n + 1);
            }
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << '\n';
        }

    }
    return 0;
}