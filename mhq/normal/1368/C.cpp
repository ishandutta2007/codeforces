#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    const int shift = 15;
    vector < pair < int, int > > ans;
    for (int i = 0; i < n; i++) {
        ans.emplace_back(i, i);
        ans.emplace_back(i, i + 1);
        ans.emplace_back(i, i - 1);
    }
    ans.emplace_back(-1, 0);
    ans.emplace_back(-1, -1);
    ans.emplace_back(n, n - 1);
    ans.emplace_back(n, n);
    cout << ans.size() << '\n';
    for (auto& it : ans) {
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}