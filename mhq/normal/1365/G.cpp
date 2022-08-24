#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll ask(vector < int >& c) {
    if (c.empty()) return 0;
    sort(c.begin(), c.end());
    cout << "? " << c.size() << " ";
    for (int v : c) cout << v << " ";
    cout << endl;
    ll resp;
    cin >> resp;
    return resp;
}
int f[1 << 15];
ll gg[15];
int bck[1 << 15];
ll ans[1488];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int sz = 0;
    for (int i = 0; i < (1 << 13); i++) {
        int bt = 0;
        for (int j = 0; j < 13; j++) {
            if (i & (1 << j)) bt++;
        }
        if (bt == 6) {
            f[sz] = i;
            bck[i] = sz;
            sz++;
        }
    }
    for (int i = 0; i < 13; i++) {
        vector < int > t;
        for (int j = 0; j < n; j++) {
            if (f[j] & (1 << i)) t.emplace_back(j + 1);
        }
        gg[i] = ask(t);
    }
    for (int i = 0; i < 63; i++) {
        int msk = 0;
        for (int j = 0; j < 13; j++) {
            if (gg[j] & (1LL << i)) msk |= (1 << j);
        }
        int bt = 0;
        for (int j = 0; j < 13; j++) {
            if (msk & (1 << j)) bt++;
        }
        assert(bt == 0 || (bt >= 6));
        if (bt > 6) {
            for (int p = 0; p < n; p++) {
                ans[p] |= (1LL << i);
            }
        }
        else if (bt == 6) {
            int where = bck[msk];
            for (int j = 0; j < n; j++) {
                if (j == where) continue;
                ans[j] |= (1LL << i);
            }
        }
    }
    cout << "! ";
    for (int p = 0; p < n; p++) cout << ans[p] << " ";
    cout << endl;
    return 0;
}