#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 100, LG = 15, MX = 1 << LG;

int n, a[N];
vector<pair<vector<int>, int>> le, ri;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 1 << LG; i++) {
        vector<int> l, r;
        for (int j = 0; j < n; j++) {
            l.push_back(__builtin_popcount((a[j] >> LG) ^ i));
            r.push_back(__builtin_popcount((a[j] & (MX - 1)) ^ i));
        }
        int mi = *min_element(l.begin(), l.end());
        for (int &v : l) {
            v -= mi;
        }
        int mx = *max_element(r.begin(), r.end());
        for (int &v : r) {
            v = mx - v;
        }
        le.push_back({l, i});
        ri.push_back({r, i});
    }
    sort(le.begin(), le.end()); sort(ri.begin(), ri.end());
    for (int i = 0, pt = 0; i < le.size() && pt < ri.size(); i++) {
        while (pt < ri.size() && ri[pt] < le[i]) {
            pt++;
        }
        if (ri[pt].fi == le[i].fi) {
            return cout << ((le[i].se << LG) ^ ri[pt].se), 0;
        }
    }
    cout << -1;
}