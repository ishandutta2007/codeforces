#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
vector<pair<int,int>> ans;
void go(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    go(l, mid);
    go(mid + 1, r);
    for (int i = l; i <= mid; i++) {
        ans.emplace_back(i, i + mid + 1 - l);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    int c = 1;
    while (2 * c <= n) c *= 2;
    go(1, c);
    go(n - c + 1, n);
    cout << ans.size() << '\n';
    for (auto& it : ans) cout << it.first << " " << it.second << '\n';
    return 0;
}