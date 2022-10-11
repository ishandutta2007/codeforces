#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int M = 15, N = 15;

int m, n;
pair<int, int> a[M], b[N];
vector<int> tot, cur;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i].fi >> b[i].se;
    }
    for (int i = 1; i <= m; i++) {
        cur.clear();
        for (int j = 1; j <= n; j++) {
            int cnt = 0;
            if (a[i].fi == b[j].fi || a[i].fi == b[j].se) {
                cnt++;
            }
            if (a[i].se == b[j].fi || a[i].se == b[j].se) {
                cnt++;
            }
            if (cnt == 1) {
                if (a[i].fi == b[j].fi || a[i].fi == b[j].se) {
                    cur.push_back(a[i].fi);
                } else {
                    cur.push_back(a[i].se);
                }
            }
        }
        sort(cur.begin(), cur.end());
        cur.erase(unique(cur.begin(), cur.end()), cur.end());
        if (cur.size() >= 2) {
            return cout << -1, 0;
        } else if (cur.size() == 1) {
            tot.push_back(cur[0]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cur.clear();
        for (int j = 1; j <= m; j++) {
            int cnt = 0;
            if (b[i].fi == a[j].fi || b[i].fi == a[j].se) {
                cnt++;
            }
            if (b[i].se == a[j].fi || b[i].se == a[j].se) {
                cnt++;
            }
            if (cnt == 1) {
                if (b[i].fi == a[j].fi || b[i].fi == a[j].se) {
                    cur.push_back(b[i].fi);
                } else {
                    cur.push_back(b[i].se);
                }
            }
        }
        sort(cur.begin(), cur.end());
        cur.erase(unique(cur.begin(), cur.end()), cur.end());
        if (cur.size() >= 2) {
            return cout << -1, 0;
        } else if (cur.size() == 1) {
            tot.push_back(cur[0]);
        }
    }
    sort(tot.begin(), tot.end());
    tot.erase(unique(tot.begin(), tot.end()), tot.end());
    if (tot.size() >= 2) {
        cout << 0;
    } else {
        cout << tot[0];
    }
}