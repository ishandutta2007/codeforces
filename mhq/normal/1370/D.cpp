#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int n, k;
int a[maxN];
bool check(int x) {
    //check odd
    bool ok = true;
    int lst = -1;
    //check odd
    int need = (k + 1) / 2;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) continue;
        if (lst == i - 1) continue;
        lst = i;
        need--;
        if (need == 0) break;
    }
    if (need == 0) {
        if (k % 2 == 0) {
            if (lst < n) {
                return true;
            }
        }
        else {
            return true;
        }
    }
    need = k / 2;
    lst = -1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > x) continue;
        if (lst == i - 1) continue;
        lst = i;
        need--;
        if (need == 0) break;
    }
    if (need == 0) {
        if (k % 2 == 1) {
            if (lst < n) {
                return true;
            }
        }
        else {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = -1;
    int r = 1e9 + 15;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
    return 0;
}