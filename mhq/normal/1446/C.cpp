#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int a[maxN];
int n;
int rec(int bit, vector<int>& f) {
    if (bit == -1) return 1;
    vector<int> le, ri;
    for (int& c : f) {
        if ((c >> bit) & 1) {
            ri.emplace_back(c);
        }
        else {
            le.emplace_back(c);
        }
    }
    f.clear();
    if (le.empty()) return rec(bit - 1, ri);
    if (ri.empty()) return rec(bit - 1, le);
    return max(rec(bit - 1, le), rec(bit - 1, ri)) + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f.emplace_back(a[i]);
    }
    sort(f.begin(), f.end());
//    cout << rec(30, f) << endl;
    cout << n - rec(30, f);

    return 0;
}