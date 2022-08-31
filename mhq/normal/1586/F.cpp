#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int k, n;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  //  freopen("input.txt", "r", stdin);
    cin >> n >> k;
    int c = 1;
    int pt = k;
    while (pt < n) {
        c++;
        pt *= k;
    }
    cout << c << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = i;
            int b = j;
            vector<int> p1(c), p2(c);
            for (int z = 0; z < c; z++) {
                p1[z] = a % k;
                a /= k;
            }
            for (int z = 0; z < c; z++) {
                p2[z] = b % k;
                b /= k;
            }
            for (int z = c - 1; z >= 0; z--) {
                if (p1[z] != p2[z]) {
                    cout << z + 1 << " ";
                    break;
                }
            }
        }
    }

    return 0;
}