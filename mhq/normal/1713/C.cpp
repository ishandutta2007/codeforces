#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool is_square(int x) {
    if (x < 0) return false;
    int t = sqrt(x) + 2;
    while (t * t > x) t--;
    return (t * t == x);
}
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
        vector<int> p(n);
        int pt = n - 1;
        while (pt >= 0) {
            for (int j = 0; j <= pt; j++) {
                if (is_square(pt + j)) {
                    for (int x = j; x <= pt; x++) {
                        p[x] = pt + j - x;
                    }
                    pt = j - 1;
                    break;
                }
            }
        }
        for (int v : p) cout << v << " ";
        cout << '\n';
    }
    return 0;
}