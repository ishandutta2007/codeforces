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
        int s = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            s += x;
        }
        if (n <= s) {
            cout << s - n<< '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }
    return 0;
}