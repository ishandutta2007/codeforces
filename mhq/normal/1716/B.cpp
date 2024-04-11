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
        cout << n << '\n';
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        for (int v : a) cout << v << " ";
        cout << '\n';
        for (int i = 0; i + 1 < n; i++) {
            swap(a[i], a[i + 1]);
            for (int v : a) cout << v << " ";
            cout << '\n';
        }
    }
    return 0;
}