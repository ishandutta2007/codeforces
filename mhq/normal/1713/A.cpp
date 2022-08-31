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
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        x.emplace_back(0);
        y.emplace_back(0);
        int T = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end()) +
                *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
        cout << 2 * T << '\n';

    }
    return 0;
}