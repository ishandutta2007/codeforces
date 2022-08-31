#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        vector < pair < pair < int, int >, int > > events;
        for (int j = 0; j < n; j++) {
            int l, r;
            cin >> l >> r;
            events.emplace_back(make_pair(l, -1), j) ;
            events.emplace_back(make_pair(r, 1), j);
        }
        sort(events.begin(), events.end());
        int bal = 0;
        vector < int > ans(n, 1);
        bool ok = false;
        for (int j = 0; j < events.size(); j++) {
            if ((bal == 0) && (j != 0)) {
                ok = true;
                break;
            }
            bal += events[j].first.second;
            ans[events[j].second] = 2;
        }
        if (!ok) {
            cout << -1 << '\n';
        }
        else {
            for (int v : ans) cout << v << " ";
            cout << '\n';
        }
    }
    return 0;
}