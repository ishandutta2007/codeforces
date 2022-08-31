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
        ll n, k;
        cin >> n >> k;
        ll cnt = 1;
        ll days = 0;
        while (cnt < n && cnt <= k) {
            cnt *= 2;
            days += 1;
        }
        if (cnt >= n) {
            cout << days << '\n';
        }
        else {
            days += (n - cnt + k - 1) / k;
            cout << days << '\n';
        }
    }
    return 0;
}