#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1e5 + 10;
int a[maxN];
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
        vector<int> p;
        p.emplace_back(-1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) p.emplace_back(i);
        }
        p.emplace_back(n);
        int f = 0;
        for (int t = 0; t + 1 < p.size(); t++) {
            if (p[t] + 1 != p[t + 1]) f++;
        }
        f = min(f, 2);
        cout << f << '\n';
    }
    return 0;
}