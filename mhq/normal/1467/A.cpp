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
        if (n == 1) {
            cout << '9' << '\n';
        }
        else if (n == 2) {
            cout << "98" << '\n';
        }
        else {
            string ans;
            int where = 1;
            int stop = 8;
            for (int j = 0; j < n; j++) {
                int dig = (abs(j - where) + stop) % 10;
                ans += (char)(dig + '0');
            }
            cout << ans << '\n';
        }
    }
    return 0;
}