#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int p[maxN];
mt19937 rnd(time(0));
int LFT = 420;
int getMed(int a, int b, int c) {
    assert(a != b && a != c && b != c);
    LFT--;
#ifdef DEBUG
    vector<int> t = {abs(p[a] - p[b]), abs(p[b] - p[c]), abs(p[a] - p[c])};
    sort(t.begin(), t.end());
    return t[1];
#endif
    cout << "? " << a << " " << b << " " << c << endl;
    int resp;
    cin >> resp;
    return resp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst = 100;
    cin >> tst;
    while (tst--) {
        LFT = 420;
        int n = 20;
        cin >> n;
#ifdef DEBUG
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
        shuffle(p + 1, p + n + 1, rnd);
        if (p[1] > p[2]) swap(p[1], p[2]);
#endif
        int BUBEN1 = n / 2 + 2;
        int x = -1;
        int y = -1;
        int z = -1;
        int c1 = -1;
        int c2 = -1;
        while (true) {
            while (true) {
                x = rnd() % n + 1;
                y = rnd() % n + 1;
                while (y == x) {
                    y = rnd() % n + 1;
                }
                z = rnd() % n + 1;
                while (z == y || z == x) {
                    z = rnd() % n + 1;
                }
                int R = getMed(x, y, z);
                if (R >= BUBEN1) {
                    break;
                }
            }
            int cc1 = -1;
            int cc2 = -1;
            int TR = 10;
            int cnt_ok = 0;
            for (int r = 0; r < 3; r++) {
                int a, b;
                if (r == 0) {
                    a = x;
                    b = y;
                } else if (r == 1) {
                    a = x;
                    b = z;
                } else {
                    a = y;
                    b = z;
                }
                bool ok = false;
                for (int it = 0; it < TR; it++) {
                    int f = rnd() % n + 1;
                    while (f == a || f == b) f = rnd() % n + 1;
                    int T = getMed(a, b, f);
                    if (T <= BUBEN1 / 2) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    cnt_ok++;
                    cc1 = a;
                    cc2 = b;
                }
            }
            if (cnt_ok != 1) continue;
            c1 = cc1;
            c2 = cc2;
            break;
        }
        vector<pair<int, int>> all;
        for (int i = 1; i <= n; i++) {
            if (c1 == i || c2 == i) continue;
            int D = getMed(c1, c2, i);
            all.emplace_back(D, i);
        }
        sort(all.begin(), all.end());
        reverse(all.begin(), all.end());
        int pos_n = all[0].second;
        int pos_he = all[1].second;
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            if (i == pos_n || i == pos_he) continue;
            int D = getMed(pos_n, pos_he, i);
            ans[i] = n - 1 - D;
        }
        ans[pos_n] = n;
        ans[pos_he] = n - 1;
        if (ans[1] > ans[2]) {
            for (int i = 1; i <= n; i++) {
                ans[i] = n + 1 - ans[i];
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
        int resp;
        cin >> resp;
#ifdef DEBUG
        for (int i = 1; i <= n; i++) assert(ans[i] == p[i]);
#endif
    }
    return 0;
}