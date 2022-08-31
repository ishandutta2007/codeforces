#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int a[maxN];
int n;
int he[maxN];
bool fr[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int r = n;
    vector<int> ones, other;
    vector<pair<int,int>> ans;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            he[i] = r;
            ans.emplace_back(r, i);
            ones.emplace_back(i);
            r--;
        }
        else if (a[i] == 2) {
            other.emplace_back(i);
            if (ones.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            int p = ones.back();
            ones.pop_back();
            he[i] = he[p];
            ans.emplace_back(he[i], i);
        }
        else if (a[i] == 3) {
            int p = -1;
            if (other.empty() && ones.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            if (!other.empty()) {
                p = other.back();
                other.pop_back();
            }
            else {
                p = ones.back();
                ones.pop_back();
            }
            assert(r > 0);
            he[i] = r;
            ans.emplace_back(he[i], i);
            ans.emplace_back(he[i], p);
            r--;
            other.emplace_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto& it : ans) {
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}