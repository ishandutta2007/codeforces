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
        for (int len = 1; len <= n; len++) {
            cout << string(len, '(') + string(len, ')');
            for (int z = 0; z < (n - len); z++) cout << "()";
            cout << '\n';
        }
    }
    return 0;
}