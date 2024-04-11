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
        vector <int > a(n);
        for (int& v : a) cin >> v;
        vector<int> b;
        vector<int> l(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i];
            if (l[i] == 0) b.emplace_back(a[i]);
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            if (l[i] == 1) cout << a[i] << " ";
            else {
                cout << b.back() << " ";
                b.pop_back();
            }
        }
        cout << '\n';
    }
    return 0;
}