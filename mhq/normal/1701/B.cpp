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
        int n;
        cin >> n;
        cout << 2 << '\n';
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                for (int j = i; j <= n; j *= 2) {
                    cout << j << " ";
                }
            }
        }
        cout << '\n';
    }
    return 0;
}