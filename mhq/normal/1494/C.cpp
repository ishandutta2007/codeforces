#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int solve(vector<int> a, vector<int> b) {
    int tot = 0;
    for (int& v : a) {
        int t = lower_bound(b.begin(), b.end(), v) - b.begin();
        if (t != b.size() && b[t] == v) tot++;
    }
    int mx = tot;
    int r = 0;
    for (int i = 0; i < a.size(); i++) {
        while (r < b.size() && b[r] <= a[i]) r++;
        if (r > 0 && b[r - 1] == a[i]) tot--;
        int ni = 2e9;
        if (i != a.size() - 1) ni = a[i + 1];
        int nr = r;
        while (nr < b.size() && b[nr] < ni) {
            int from = b[nr];
            int to = b[nr] - i;
            int c1 = lower_bound(b.begin(), b.end(), to) - b.begin();
            int c2 = upper_bound(b.begin(), b.end(), from) - b.begin();
            mx = max(mx, tot + (c2 - c1));
            nr++;
        }
    }
    return mx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while(tst--) {
        int n, m;
        cin >> n >> m;
        vector<int> a_pos, a_neg, b_pos, b_neg;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x < 0) {
                a_neg.emplace_back(abs(x));
            }
            else {
                a_pos.emplace_back(x);
            }
        }
        reverse(a_neg.begin(), a_neg.end());
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            if (x < 0) {
                b_neg.emplace_back(abs(x));
            }
            else {
                b_pos.emplace_back(x);
            }
        }
        reverse(b_neg.begin(), b_neg.end());
        cout << solve(a_pos, b_pos) + solve(a_neg, b_neg) << '\n';
    }
    return 0;
}