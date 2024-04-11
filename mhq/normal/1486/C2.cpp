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
    p = ask(1, n);
    bool le = false;
    if (l < p && ask(l, p) == p) {
        r = p;
        le = true;
    }
    else {
        l = p;
        le = false;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (le) {
            if (ask(mid, p) == p) l = mid;
            else r = mid;
        }
        else {
            if (ask(p, mid) == p) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
    }
    if (le) {
        cout << "! " << l << endl;
    }
    else {
        cout << "! " << r << endl;
    }
    return 0;
}