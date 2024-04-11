#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 105;
int a[maxN];
int ask() {
    cout << "? ";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    int resp;
    cin >> resp;
    return resp;
}
int p[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n;
    int val = n;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - 1; j++) a[j] = 1;
        a[n] = i;
        int k = ask();
        if (k != 0) {
            val = n - i + 1;
            break;
        }
    }
    p[n] = val;
    for (int he = 1; he <= n; he++) {
        if (he == val) continue;
        for (int z = 1; z <= n - 1; z++) a[z] = val;
        a[n] = he;
        int k = ask();
        assert(k != 0);
        p[k] = he;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << endl;
    return 0;
}