#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int& v : a) cin >> v;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            cout << a[i] << " " << a[2 * n - i - 1] << " ";
        }
        cout << '\n';
    }
    return 0;
}