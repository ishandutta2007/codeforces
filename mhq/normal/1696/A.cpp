#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2005;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n, z;
        cin >> n >> z;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, (a[i] | z));
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    mx = max(mx, (a[i] | z) | (a[j] & z));
                }
            }
        }
        cout << mx << '\n';

    }
    return 0;
}