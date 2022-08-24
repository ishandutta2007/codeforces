#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < ll, int > > pr;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            int ex = 0;
            while (n % i == 0) {
                n /= i;
                ex++;
            }
            pr.emplace_back(i, ex);
        }
    }
    if (n > 1) pr.emplace_back(n, 1);
    if (pr.size() != 1) {
        cout << 1;
        return 0;
    }
    else {
        cout << pr[0].first;
    }
    return 0;
}