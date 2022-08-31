#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int num[] = {11, 111, 1111, 11111};
const int maxN = 1e6 + 10;
bool can[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    can[0] = true;
    for (int i = 1; i < maxN; i++) {
        for (int j = 0; j < 4; j++) {
            if (i >= num[j] && can[i - num[j]]) can[i] = true;
        }
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        if (n < maxN) {
            if (can[n]) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}