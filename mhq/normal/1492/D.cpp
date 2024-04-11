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
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 0) {
        cout << "Yes\n";
        string s = string(b, '1') + string(a, '0');
        cout << s << '\n' << s;
        return 0;
    }
    if (a == 0 || b == 1) {
        cout << "No";
        return 0;
    }
    if (k > a + b - 2) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    int c = -1;
    int d = -1;
    for (int x = 0; x <= k; x++) {
        int y = k - 1 - x;
        if (x >= 0 && x <= a - 1 && y >= 0 && y <= b - 2) {
            c = x;
            d = y;
            break;
        }
    }
    assert(c != -1);
    cout << "11" + string(c, '0') + string(d, '1') + '0' + string(a - 1 - c, '0') + string(b - 2 - d, '1') << '\n';
    cout << "10" + string(c, '0') + string(d, '1') + '1' + string(a - 1 - c, '0') + string(b - 2 - d, '1') << '\n';
    return 0;
}