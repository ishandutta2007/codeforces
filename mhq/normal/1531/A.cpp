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
    vector<string> cur(n + 1);
    cur[0] = "unlock";
    for (int i = 1; i <= n; i++) {
        cin >> cur[i];
    }
    auto is_color = [&](string& t) {
        return t != "lock" && t != "unlock";
    };
    set<int> not_colors;
    set<int> good;
    for (int i = 0; i <= n; i++) {
        if (!is_color(cur[i])) not_colors.insert(i);
        if (cur[i] == "unlock") {
            if (i < n && is_color(cur[i + 1])) good.insert(i);
        }
    }
    not_colors.insert(n + 1);
    auto printAns = [&]() {
        if (good.empty()) {
            cout << "blue" << '\n';
        }
        else {
            int pos = *(--good.end());
            cout << cur[(*not_colors.lower_bound(pos + 1)) - 1] << '\n';
        }
    };
    printAns();
    return 0;
}