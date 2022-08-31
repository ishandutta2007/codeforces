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
        ll n, a, b;
        cin >> a >> b >> n;
        int steps = 0;
        while (max(a, b) <= n) {
            if (a < b) swap(a, b);
            b += a;
            steps++;
        }
        cout << steps << '\n';
    }
    return 0;
}