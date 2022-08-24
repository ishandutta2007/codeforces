#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1005;
int n, k;
vector < int > inds[maxN];
int QUE = 0;
int ask(vector < int >& g) {
    if (g.empty()) return 0;
    QUE++;
    if (QUE == 13) {
        assert(false);
        exit(0);
    }
    sort(g.begin(), g.end());
    cout << "? " << g.size() << " ";
    for (int v : g) cout << v << " ";
    cout << endl;
    int resp;
    cin >> resp;
    return resp;
}
bool used[maxN];
int ask_inds(int l, int r) {
    vector < int > gg;
    for (int j = l; j <= r; j++) {
        for (int p : inds[j]) gg.emplace_back(p);
    }
    return ask(gg);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        QUE = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) inds[i].clear();
        memset(used, 0, sizeof used);
        for (int i = 1; i <= k; i++) {
            int p;
            cin >> p;
            inds[i].resize(p);
            for (int& v : inds[i]) {
                cin >> v;
                used[v] = true;
            }
        }
        vector < int > all(n);
        iota(all.begin(), all.end(), 1);
        vector < int > other;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) other.emplace_back(i);
        }
//        int mx_other = ask(other);
        int mx_all = ask_inds(1, k);
        int l = 0;
        int r = k;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int val = ask_inds(1, mid);
            if (val == mx_all) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        assert(1 <= r && r <= k);
        vector < int > tt;
        for (int j = 1; j <= k; j++) {
            if (j == r) continue;
            for (int p : inds[j]) tt.emplace_back(p);
        }
        for (int p : other) tt.emplace_back(p);
        int sec_mx = ask(tt);
        cout << "! ";
        for (int i = 1; i <= k; i++) {
            if (i == r) {
                cout << sec_mx << " ";
            }
            else {
                cout << max(mx_all, sec_mx) << " ";
            }
        }
        cout << endl;
        string resp;
        cin >> resp;
        if (resp == "Incorrect") {
            exit(0);
        }
    }
    return 0;
}