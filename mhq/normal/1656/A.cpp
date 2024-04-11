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
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.emplace_back(a, i);
        }
        sort(v.begin(), v.end());
        cout << v[0].second + 1 << " " << v.back().second + 1 << '\n';
    }
    return 0;
}