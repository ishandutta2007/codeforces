#include <bits/stdc++.h>
using namespace std;

const int N = 4E5 + 5, MX = 1E6 + 5;

int t, n, a[N], cnt[MX];
vector<int> ve;

void solve() {
    int g = 0, b = 0, s = 0, cur = 0;
    int le = 0, ri = 0, haf = 0, pt = 0;
    ve.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        ve.push_back(a[i]);
    }
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    for (int &v : ve) {
        cur += cnt[v];
        if (cur <= n / 2) {
            haf = cur;
        }
    }
    for (int i = 0; i < ve.size(); i++) {
        le += cnt[ve[i]]; ri -= cnt[ve[i]];
        while (ri <= le && le + ri < haf && pt < ve.size()) {
            ri += cnt[ve[pt++]];
        }
        if (ri <= le) {
            break;
        }
        g = le; s = ri; b = haf - le - ri;
        break;
    }
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]--;
    }
    if (s > g && b > g && g > 0) {
        cout << g << " " << s << " " << b << '\n';
    } else {
        cout << "0 0 0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}