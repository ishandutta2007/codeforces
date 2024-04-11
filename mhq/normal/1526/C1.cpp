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
    int n;
    cin >> n;
    priority_queue<ll> all;
    ll f = 0;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        f += x;
        all.push(-x);
        while (f < 0) {
            auto it = all.top();
            f -= -it;
            all.pop();
        }
    }
    cout << all.size();
    return 0;
}