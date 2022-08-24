#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e3 + 15;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    if (n <= 3) {
        cout << 0 << endl;
        return 0;
    }
    int bestk = 1;
    vector < int > for_best;
    int need = 0;
    for (int k = 1; k <= n; k++) {
        int cnt = 0;
        int tot_ok = 0;
        vector < int > cur;
        for (int i = 1; i <= n - 1; i++) {
            if (cnt == k - 1) {
                cnt = 0;
            }
            else {
                cnt++;
                tot_ok++;
                cur.emplace_back(i);
            }
        }
        int val = tot_ok - k + 1;
        if (val > need) {
            bestk = k;
            for_best = cur;
            need = val;
        }
    }
    while (true) {
        int f = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i]) f++;
        }
        if (f >= need) {
            cout << 0 << endl;
            return 0;
        }
        vector < int > fs;
        for (int p : for_best) {
            if (a[p] == 0) fs.emplace_back(p);
        }
        assert(fs.size() >= bestk);
        cout << bestk << '\n';
        for (int v = 0; v < bestk; v++) {
            cout << fs[v] << " ";
            a[fs[v]] = 1;
        }
        cout << endl;
        int resp;
        cin >> resp;
        for (int p = resp; p <= resp + bestk - 1; p++) {
            a[(p + n - 1) % n + 1] = 0;
        }
    }
    assert(false);
    return 0;
}