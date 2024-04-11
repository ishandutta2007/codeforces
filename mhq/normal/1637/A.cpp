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
        vector<int> a(n);
        for (int& v : a) cin >> v;
        auto b = a;
        sort(b.begin(), b.end());
        if (b != a) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}