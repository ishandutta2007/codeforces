#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
vector < ll > who[70];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (int j = 0; ; j++) {
            if (x % (1LL << j)) {
                who[j - 1].push_back(x);
                break;
            }
        }
    }
    pair < int, int > best = make_pair(-1, -1);
    for (int i = 0; i < 70; i++) {
        best = max(best, make_pair((int)who[i].size(), i));
    }
    cout << n - best.first << '\n';
    for (int i = 0; i < 70; i++) {
        if (i == best.second) continue;
        for (ll p : who[i]) cout << p << " ";
    }
    return 0;
}