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
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;
        vector<pair<int,int>> x, y;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') x.emplace_back(p[i], i);
            else y.emplace_back(p[i], i);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        vector<int> ans(n);
        int st = 1;
        for (auto& it : x) {
            ans[it.second] = st;
            st++;
        }
        for (auto& it : y) {
            ans[it.second] = st;
            st++;
        }
        for (int v : ans) cout << v << " ";
        cout << '\n';
    }
    return 0;
}