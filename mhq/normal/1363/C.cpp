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
        int n, x;
        cin >> n >> x;
        vector < int > deg(n + 1);
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            deg[a]++;
            deg[b]++;
        }
        if (deg[x] == 1 || n == 1) {
            cout << "Ayush" << '\n';
        }
        else if (n % 2 == 0) {
            cout << "Ayush\n";
        }
        else {
            cout << "Ashish\n";
        }
    }
    return 0;
}