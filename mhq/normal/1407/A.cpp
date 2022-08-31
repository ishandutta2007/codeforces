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
        vector < int > zer, one;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == 0) zer.emplace_back(x);
            else one.emplace_back(x);
        }
        if (zer.size() >= n / 2) {
            cout << zer.size() << '\n';
            for (int v : zer) cout << v << " ";
            cout << '\n';
        }
        else {
            if (one.size() % 2 == 1) one.pop_back();
            assert(one.size() >= n / 2);
            cout << one.size() << '\n';
            for (int v : one) cout << v << " ";
            cout << '\n';
        }
    }
    return 0;
}