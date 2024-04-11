#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 55;
int x[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        set<int> p;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (p.count(x)) {
                x++;
            }
            p.insert(x);
        }
        cout << p.size() << '\n';
    }
    return 0;
}