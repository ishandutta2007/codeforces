#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int resp;
    cin >> resp;
    return resp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int p = -1;
    int l = 1;
    int r = n;
    ld alpha = (sqrt(5) - 1) / 2;
    while (true) {
        if (r - l + 1 == 1) {
            cout << "! " << l << endl;
            return 0;
        }
        if (p == -1) {
            p = ask(l, r);
        }
        if (r - l + 1 == 2) {
            int other = l + r - p;
            cout << "! " << other << endl;
            return 0;
        }
        int sz = (alpha * (r - l + 1));
        sz = min(sz, r - l);
        sz = max(sz, min(p - l + 1, r - p + 1));
        sz = max(sz, 2);
        assert(1 <= sz && sz <= r - l);
        if (sz >= p - l + 1) {
            int resp = ask(l, l + sz - 1);
            if (resp == p) {
                r = l + sz - 1;
            }
            else {
                l = l + sz;
                p = -1;
            }
        }
        else {
            int resp = ask(r - sz + 1, r);
            if (resp == p) {
                l = r - sz + 1;
            }
            else {
                r = r - sz;
                p = -1;
            }
        }
    }
    return 0;
}