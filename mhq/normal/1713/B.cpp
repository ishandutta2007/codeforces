#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& v : a) cin >> v;
        int pos = max_element(a.begin(), a.end()) - a.begin();
        bool ok = true;
        for (int i = 0; i + 1 <= pos; i++) {
            if (a[i] > a[i + 1]) ok = false;
        }
        for (int i = pos; i + 1 < n; i++) {
            if (a[i] < a[i + 1]) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}