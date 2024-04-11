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
        bool ok = false;
        bool bok = false;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int x;
                cin >> x;
                if (x == 0) ok = true;
                if (x == 1) bok = true;
            }
        }
        if (!bok) cout << 0 << '\n';
        else if (ok) cout << 1 << '\n';
        else cout << 2 << '\n';

    }
    return 0;
}