#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int an = 0;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            if (i == 0) an = c;
            else an &= c;
        }
        cout << an << '\n';
    }
    return 0;
}