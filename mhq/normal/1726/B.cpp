#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        if (m < n) {
            cout << "No\n";
            continue;
        }
        if (n % 2 == 0 && m % 2 != 0) {
            cout << "No\n";
            continue;
        }
        if (n % 2 == 1) {
            cout << "Yes\n";
            for (int i = 0; i < (n - 1); i++) {
                cout << 1 << " ";
            }
            cout << (m - (n - 1)) << '\n';
        }
        else {
            cout << "Yes\n";
            for (int i = 0; i < (n - 2); i++) {
                cout << 1 << " ";
            }
            cout << (m - (n - 2)) / 2 << " " << (m - (n - 2)) / 2 << '\n';
        }
    }
    return 0;
}