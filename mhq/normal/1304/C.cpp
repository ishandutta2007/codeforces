#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int t[105], h[105], l[105];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> l[i] >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (t[i] > t[j]) {
                swap(t[i], t[j]);
                swap(l[i], l[j]);
                swap(h[i], h[j]);
            }
        }
    }
    int l = m;
    int r = m;
    int ti = 0;
    for (int i = 1; i <= n; i++) {
        int new_le = l - (t[i] - ti);
        int new_ri = r + (t[i] - ti);
        if (max(new_le, ::l[i]) > min(new_ri, h[i])) {
            cout << "NO\n";
            return;
        }
        l = max(new_le, ::l[i]);
        r = min(new_ri, h[i]);
        ti = t[i];
    }
    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}