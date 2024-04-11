#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int ans[maxN];
int where[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    set<int> s;
    for (int i = 1; i <= 2 * n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            s.insert(i);
        }
        else {
            int x;
            cin >> x;
            where[x] = i;
            ans[i] = -1;
            s.insert(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        auto it = s.lower_bound(where[i]);
        if (it == s.begin()) {
            cout << "NO\n";
            exit(0);
        }
        --it;
        int c = *it;
        if (ans[c] == -1) {
            cout << "NO\n";
            exit(0);
        }
        s.erase(c);
        s.erase(where[i]);
        ans[c] = i;
    }
    cout << "YES\n";
    for (int i = 1; i <= 2 * n; i++) {
        if (ans[i] != -1) cout << ans[i] << " ";
    }
    return 0;
}